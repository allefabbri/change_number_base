#include <stdio.h>
#include <stdlib.h>

#include "const.h"

typedef struct{
  int * ptr;
  int size;
} darray;

darray change_basis_stru(int x, int b){
  int temp=x;
  darray digits;
  digits.size=0;
  while(temp!=0){
    digits.size++;
    temp/=b;
  }
  digits.ptr = (int *) malloc(digits.size*sizeof(int));
  for(temp=0; temp<digits.size; temp++){
    digits.ptr[digits.size-1-temp] = x%b;
    x/=b;
  }
  return digits;
};

int main(){
  int x=NUMBER, i, check=0;
  
  darray digits;
  digits = change_basis_stru(x,BASE);

  printf("size of digits : %d\n\n", digits.size*sizeof(*digits.ptr));

  printf("Base 10 -> %d\n",x);
  printf("Base %d -> ",BASE);
  for(i=0; i<digits.size; i++){
    printf("%d ",digits.ptr[i]);
    check = check*BASE+digits.ptr[i];
  }
  printf(" \nBase 10 -> %d\n",check);

  return 0;
}
