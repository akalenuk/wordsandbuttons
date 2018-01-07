#define LOOP_TO_0(ID, N, BODY) {int ID; switch(N){\
case 4: ID=4;(BODY);\
case 3: ID=3;(BODY);\
case 2: ID=2;(BODY);\
case 1: ID=1;(BODY);\
case 0: ID=0;(BODY);\
}}

#define FACTORIAL(X, Y) Y = 1; LOOP_TO_0(i, X , Y *= (i+(i==0)));

#include "stdio.h"

int main(){
  int y;
  int x = 4;
  FACTORIAL(x, y);
  printf("%d\n", y);
}

