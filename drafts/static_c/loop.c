
#define LOOP_0(ID, I, body) ID = I; (body);}
#define LOOP_1(ID, I, body) ID = I; (body); LOOP_0(ID, I-1, body)
#define LOOP_2(ID, I, body) ID = I; (body); LOOP_1(ID, I-1, body)
#define LOOP_3(ID, I, body) ID = I; (body); LOOP_2(ID, I-1, body)
#define LOOP_4(ID, I, body) ID = I; (body); LOOP_3(ID, I-1, body)
#define LOOP_TO_0(ID, I, body) {int ID; LOOP_##I(ID, I, body) 

#define FACTORIAL(X, Y) Y = 1; LOOP_TO_0(i, X , Y *= (i+(i==0)));

#include "stdio.h"

int main(){
  int y;
  FACTORIAL(4, y);
  printf("%d\n", y);
}

