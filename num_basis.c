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
