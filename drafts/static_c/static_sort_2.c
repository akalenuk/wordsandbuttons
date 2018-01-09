#define LOOP_TO_0(ID, N, BODY) {int ID; switch(N){\
case 4: ID=4;{BODY};\
case 3: ID=3;{BODY};\
case 2: ID=2;{BODY};\
case 1: ID=1;{BODY};\
case 0: ID=0;{BODY};\
}}

#define STATIC_SORT_INT(a) \
  LOOP_TO_0(i, sizeof(a)/sizeof(a[0]) - 2, LOOP_TO_0(j, i, \
    int k = i-j; \
    if(a[k] > a[k+1]){ \
      int temp = a[k]; \
      a[k] = a[k+1]; \
      a[k+1] = temp; \
    } \
  ));

#include "stdio.h"
#include "stdlib.h"

int main(){
  int a[4] = {1, 5, 2, 4};
  STATIC_SORT_INT(a);
  printf("%d %d %d %d\n", a[0], a[1], a[2], a[3]);
}

