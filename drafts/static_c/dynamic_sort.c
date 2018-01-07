#include "stdio.h"
#include "stdlib.h"

inline void inner_loop(int j, int i, int n, int* a){
  if(j < n-i-1){
    int d = abs(a[j]-a[j+1]);
    int s = a[j]+a[j+1];
    a[j] = (s-d) / 2;
    a[j+1] = (s+d) / 2;
    inner_loop(j + (j < n-i-1), i, n, a);
  }
}

inline void outer_loop(int i, int n, int* a){
  if(i < n-1){
    inner_loop(0, i, n, a);
    outer_loop(i + (i < n-1), n, a);
  }
}

inline void static_sort(int n, int* a){
  outer_loop(0, n, a);
}

int main(){
  int a[8] = {1,5,2,9, 6,7,8,5};
  static_sort(8, a);
  for(int i = 0; i < 8; ++i)
    printf("%d", a[i]);
  return 0;
}
