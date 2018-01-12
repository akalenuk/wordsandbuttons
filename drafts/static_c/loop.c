#define F_0(N) ((N)==1 ? 1 : (N)*F_1((N)-1))
#define F_1(N) ((N)==1 ? 1 : (N)*F_2((N)-1))
#define F_2(N) ((N)==1 ? 1 : (N)*F_3((N)-1))
#define F_3(N) ((N)==1 ? 1 : (N)*F_4((N)-1))
#define F_4(N) ((N)==1 ? 1 : (N)*F_5((N)-1))
#define F_5(N) ((N)==1 ? 1 : (N)*F_6((N)-1))
#define F_6(N) ((N)==1 ? 1 : (N)*F_7((N)-1))
#define F_7(N) ((N)==1 ? 1 : (N)*F_8((N)-1))
#define F_8(N)  (1)

int f_8(int i) {return 1;}
int f_7(int i) {return i == 1 ? 1 : i*f_8(i-1);}
int f_6(int i) {return i == 1 ? 1 : i*f_7(i-1);}
int f_5(int i) {return i == 1 ? 1 : i*f_6(i-1);}
int f_4(int i) {return i == 1 ? 1 : i*f_5(i-1);}
int f_3(int i) {return i == 1 ? 1 : i*f_4(i-1);}
int f_2(int i) {return i == 1 ? 1 : i*f_3(i-1);}
int f_1(int i) {return i == 1 ? 1 : i*f_2(i-1);}
int f_0(int i) {return i == 1 ? 1 : i*f_1(i-1);}

#define RECURSIVE(PREFIX, CHUNK1, SUFFIX, END_SUFFIX) \
PREFIX##0##CHUNK1##1##SUFFIX \
PREFIX##1##CHUNK1##2##SUFFIX \
PREFIX##2##CHUNK1##3##SUFFIX \
PREFIX##3##CHUNK1##4##SUFFIX \
PREFIX##4##CHUNK1##5##SUFFIX \
PREFIX##5##CHUNK1##6##SUFFIX \
PREFIX##6##CHUNK1##7##SUFFIX \
PREFIX##7##CHUNK1##8##SUFFIX \
PREFIX##8##END_SUFFIX 

REFURSIVE(int ff_, (int i){return i == 1 ? 1 : i*ff_, (i-1);}, (int){return 0;})

#include "stdio.h"
#include "stdlib.h"

int main(){
  printf("%d", ff_0(4));  
}

