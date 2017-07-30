#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#include "my_macros.h"

int min_count(vector<int> cs, int s){
  vector<int> d(s+1, 1e9);
  int o = 1e9;
  d[0] = 0;
  REP(i, 1, s){
    o = 1e9;
    for(auto c: cs){
      if(i >= c){
	o = min(d[i-c] + 1, o);
      }
    }
    d[i] = o;
  }
  return d[s];
}

int main(){
  vector<int> cs = {{1,3,4}};
  REP(i, 0, 10){    
    cout << i << ": " << min_count(cs, i) << endl;
  }
  return 0;
}
