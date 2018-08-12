#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define VERSION 1
#define BUFSIZE 8096
#define ERROR      42
#define LOG        44
#define FORBIDDEN 403
#define NOTFOUND  404

#ifndef SIGCLD
#   define SIGCLD SIGCHLD
#endif


/* this is a child web server process, so we can exit on errors */
void web(int fd)
{
  static char request[BUFSIZE+1]; 
  static char response[BUFSIZE+1]; 

  ssize_t ret = read(fd,request,BUFSIZE);   /* read Web request in one go */
  if(ret == 0 || ret == -1) {  /* read failure stop now */
    return;
  }
  if(ret > 0 && ret < BUFSIZE)  /* return code is valid chars */
    request[ret] = 0;    /* terminate the buffer */
  else 
    request[0] = 0;

  if( strncmp(request,"GET ",4) && strncmp(request,"get ",4) ) {
    return;
  }
  ssize_t request_size = 0;
  for(ssize_t i = 4; i < BUFSIZE; i++) { /* null terminate after the second space to ignore extra stuff */
    if(request[i] == ' ') { /* string is "GET URL " +lots of other stuff */
      request[i] = 0;
      request_size = i;
      break;
    }
  }

  (void)sprintf(response,"HTTP/1.1 200 OK\nServer: wabserver/%d.0\nContent-Length: %ld\nConnection: close\nContent-Type: text/html\n\n", VERSION, request_size); /* Header + a blank line */
  (void)strcat(response, request);
  (void)write(fd, response, strlen(response));

  sleep(1);  /* allow socket to drain before signalling the socket is closed */
  close(fd);
  exit(1);
}

int main(int argc, char **argv)
{
  int i, port, pid, listenfd, socketfd, hit;
  socklen_t length;
  static struct sockaddr_in cli_addr; /* static = initialised to zeros */
  static struct sockaddr_in serv_addr; /* static = initialised to zeros */

  if( argc < 2  || argc > 2) {
    (void)printf("Usage: wabserver port_number\n\n");
    exit(0);
  }
  /* Become deamon + unstopable and no zombies children (= no wait()) */
  if(fork() != 0)
    return 0; /* parent returns OK to shell */
  (void)signal(SIGCLD, SIG_IGN); /* ignore child death */
  (void)signal(SIGHUP, SIG_IGN); /* ignore terminal hangups */
  for(i=0;i<32;i++)
    (void)close(i);    /* close open files */
  (void)setpgrp();    /* break away from process group */
  /* setup the network socket */
  if((listenfd = socket(AF_INET, SOCK_STREAM,0)) <0)
    return -1;
  port = atoi(argv[1]);
  if(port < 0 || port >60000)
    return -2;
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  serv_addr.sin_port = htons(port);
  if(bind(listenfd, (struct sockaddr *)&serv_addr,sizeof(serv_addr)) <0)
    return -3;    
  if( listen(listenfd,64) <0)
    return -4;
  for(hit=1; ;hit++) {
    length = sizeof(cli_addr);
    if((socketfd = accept(listenfd, (struct sockaddr *)&cli_addr, &length)) < 0)
      return -5;
    if((pid = fork()) < 0) {
      return -6;
    }
    else {
      if(pid == 0) {   /* child */
        (void)close(listenfd);
        web(socketfd); /* never returns */
      } else {   /* parent */
        (void)close(socketfd);
      }
    }
  }
}
