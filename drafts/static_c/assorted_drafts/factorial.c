
#define LOOP_0(ID, body) ID = 0; (body);}
#define LOOP_1(ID, body) ID = 1; (body); LOOP_0(ID, body)
#define LOOP_2(ID, body) ID = 2; (body); LOOP_1(ID, body)
#define LOOP_3(ID, body) ID = 3; (body); LOOP_2(ID, body)
#define LOOP_4(ID, body) ID = 4; (body); LOOP_3(ID, body)
#define LOOP_TO_0(ID, I, body) {int ID; LOOP_##I(ID, body) 

#define FACTORIAL(X, Y) Y = 1; LOOP_TO_0(i, X , Y *= (i+(i==0)));

#include "stdio.h"

int main(){
  int y;
  FACTORIAL(4, y);
  printf("%d\n", y);
}

