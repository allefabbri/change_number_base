#include <stdio.h>
#include <stdlib.h>

#include "const.h"

int * change_basis_ptr(int x, int b, int * ptr_size){
  int temp=x;
  int * ptr;
  *ptr_size=0;
  while(temp!=0){
    (*ptr_size)++;
    temp/=b;
  }
  ptr = (int *) malloc(*ptr_size*sizeof(int));
  for(temp=0; temp<*ptr_size; temp++){
    ptr[*ptr_size-1-temp] = x%b;
    x/=b;
  }
  return ptr;
};

int main(){
  int x=NUMBER, ptr_size=0, i, check=0;
  int * ptr;

  ptr = change_basis_ptr(x,BASE,&ptr_size);

  printf("Base 10 -> %d\n",x);
  printf("Base %d -> ",BASE);
  for(i=0; i<ptr_size; i++){
    printf("%d ",ptr[i]);
    check = check*BASE+ptr[i];
  }
  printf(" \nBase 10 -> %d\n",check);

  return 0;
}
