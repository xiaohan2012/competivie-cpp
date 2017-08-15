#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#include "my_macros.h"

vector<int> count(int ss[], int n, int k){
  vector<int> r(k, 0);

  // important: n+1 (beucase 0...n has n+1 numbers)
  int d[1<<(n+1)];

  REP(i, 0, (1<<(n+1))-1)
    d[i] = 0;

  REP(i, 0, k-1)
    d[ss[i]] = 1;
    
  REP(i, 0, n){
    REP(s, 0, (1<<(n+1))-1){
      if(s&(1<<i)) //  remove i from s if i in s
	d[s] += d[s^(1<<i)];
    }
  }

  REP(i, 0, k-1)
    r[i] = d[ss[i]];
  
  return r;
}

int main(){
  int n = 5, k=5;
  int ss[n];

  REP(i, 0, n-1)
    ss[i]=0;

  ss[0] |= 1;  // 0
  ss[1] |= (1 | (1<<2)); // 0 2
  ss[2] |= ((1<<1) | (1<<4)); // 1 4
  ss[3] |= (1 | (1<<1)| (1<<4)); // 0 1 4
  ss[4] |= ((1<<1) | (1<<4) | (1<<5)); // 1 4 5

  print_vector(count(ss, n, k));
  return 0;
}
