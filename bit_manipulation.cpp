#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#include "my_macros.h"

int main(){
  cout << "adding elements to set" << endl;
  // add number 1,3,5,7 to set {0, ..., 31}
  int s = 0;
  s |= (1 << 1);
  s |= (1 << 3);
  s |= (1 << 5);
  s |= (1 << 7);
  REP(i, 0, 31){  // check each position
    if(s & (1<<i)) cout << i << " ";
  }
  cout << endl;

  cout << "set intersection" << endl;
  int x = (1<<1) | (1<<3) | (1<<5) | (1<<7);
  int y = (1<<2) | (1<<3) | (1<<5) | (1<<8);
  int z = x & y;
  cout << "intersection:" << endl;
  REP(i, 0, 31){  // check each position
    if(z & (1<<i)) cout << i << " ";
  }
  cout << endl;

  
  return 0;
}
