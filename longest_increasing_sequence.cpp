#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#include "my_macros.h"

int f(vector<int> x){
  vector<int> d(x.size(), 0);
  d[0] = 1;
  int o = 0, p = 0;
  REP(i, 0, (int)x.size()-1){
    p = 1;
    REP(j, 0, i-1){
      if(x[i] > x[j]){
	p = max(p, d[j] + 1);
      }
    }
    d[i] = p;
    o = max(o, p);
  }
  print_vector(d);
  return o;
}

int main(){
  vector<int> x = {{6, 2, 5, 1, 7, 4, 8, 3}};
  cout << f(x) << endl; // 4
  return 0;
}
