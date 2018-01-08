#define RUNTIME_SORT_INT(a) \
  for(int i = sizeof(a)/sizeof(a[0]) - 2; i >= 0; --i) \
    for(int j = i; j>=0; --j){ \
      int k = i-j; \
      if(a[k]>a[k+1]){ \
        int temp = a[k]; a[k] = a[k+1]; a[k+1] = temp; \
      } \
    }

#include "stdio.h"
#include "stdlib.h"

int main(){
  int a[4] = {1, 5, 2, 4};
  RUNTIME_SORT_INT(a);
  printf("%d %d %d %d\n", a[0], a[1], a[2], a[3]);
}

