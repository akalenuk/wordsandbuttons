#include<stdio.h>
#include<string.h>
#include<strings.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<signal.h>
#include<fcntl.h>
 
int main(int argc, char *argv[])
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv_addr;
    bzero((char *)&serv_addr, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_addr.s_addr = INADDR_ANY;
        serv_addr.sin_port = htons(8080);
    bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    listen(sockfd, 5);
    while (1) {
        int cfd  = accept(sockfd, 0, 0);
        char *s = "HTTP/1.0 200\r\nContent-type:text/html\r\n\r\n<h1>Hello world!</h1>"; 
        if (fork()==0) {
            write(cfd, s, strlen(s));
            shutdown(cfd, SHUT_RDWR);
            close(cfd);
        }   
    }
 
    return 0;
}
