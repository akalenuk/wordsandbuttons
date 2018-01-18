#define F_0(N) ((N)==1 ? 1 : (N)*F_1((N)-1))
#define F_1(N) ((N)==1 ? 1 : (N)*F_2((N)-1))
#define F_2(N) ((N)==1 ? 1 : (N)*F_3((N)-1))
#define F_3(N) ((N)==1 ? 1 : (N)*F_4((N)-1))
#define F_4(N) ((N)==1 ? 1 : (N)*F_5((N)-1))
#define F_5(N) ((N)==1 ? 1 : (N)*F_6((N)-1))
#define F_6(N) ((N)==1 ? 1 : (N)*F_7((N)-1))
#define F_7(N) ((N)==1 ? 1 : (N)*F_8((N)-1))
#define F_8(N)  (1)

inline int f_8(int i) {return 1;}
inline int f_7(int i) {return i == 1 ? 1 : i*f_8(i-1);}
inline int f_6(int i) {return i == 1 ? 1 : i*f_7(i-1);}
inline int f_5(int i) {return i == 1 ? 1 : i*f_6(i-1);}
inline int f_4(int i) {return i == 1 ? 1 : i*f_5(i-1);}
inline int f_3(int i) {return i == 1 ? 1 : i*f_4(i-1);}
inline int f_2(int i) {return i == 1 ? 1 : i*f_3(i-1);}
inline int f_1(int i) {return i == 1 ? 1 : i*f_2(i-1);}
inline int f_0(int i) {return i == 1 ? 1 : i*f_1(i-1);}

#define RECURSIVE(PREFIX, CHUNK1, SUFFIX, END_SUFFIX) \
inline PREFIX##_8 END_SUFFIX \
inline PREFIX##_7 CHUNK1##_8 SUFFIX \
inline PREFIX##_6 CHUNK1##_7 SUFFIX \
inline PREFIX##_5 CHUNK1##_6 SUFFIX \
inline PREFIX##_4 CHUNK1##_5 SUFFIX \
inline PREFIX##_3 CHUNK1##_4 SUFFIX \
inline PREFIX##_2 CHUNK1##_3 SUFFIX \
inline PREFIX##_1 CHUNK1##_2 SUFFIX \
inline PREFIX##_0 CHUNK1##_1 SUFFIX 


RECURSIVE(int ff, (int i){return i == 1 ? 1 : i*ff, (i-1);},   (int i){return 0;})

#include "stdio.h"
#include "stdlib.h"

int main(){
  printf("%d", ff_0(4));  
}

