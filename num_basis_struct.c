// Copyright 2015, Alessandro Fabbri
// for any question, please mail rommacc@yahoo.it

/************************************************************************
* This program is free software: you can redistribute it and/or modify  *
* it under the terms of the GNU General Public License as published by  *
* the Free Software Foundation, either version 3 of the License, or     *
* (at your option) any later version.                                   *
*                                                                       *
* This program is distributed in the hope that it will be useful,       *
* but WITHOUT ANY WARRANTY; without even the implied warranty of        *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
* GNU General Public License for more details.                          *
*                                                                       *
* You should have received a copy of the GNU General Public License     *
* along with this program.  If not, see <http://www.gnu.org/licenses/>. *
************************************************************************/

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
