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