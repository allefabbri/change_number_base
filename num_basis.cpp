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

#include <iostream>
#include <vector>
#include <algorithm>

#include "const.h"

std::vector<int> change_base(int x, int b){
  std::vector<int> d;
  while(x!=0){
    d.push_back(x%b);
    x/=b;
  }
  std::reverse(d.begin(),d.end()); 
  return d;
};

int main(){
  int x=NUMBER;
  std::vector<int> d;

  d = change_base(x, BASE);

  std::cout << "Base 10 -> " << x << std::endl;
  std::cout << "Base " << BASE << " -> ";
  for(auto di : d) std::cout << di << " ";
  std::cout << std::endl;

  int temp=0;
  for(auto di : d) temp = temp*BASE+di;
  std::cout << "Base 10 -> " << temp << std::endl;

  return 0;
}