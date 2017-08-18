#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#include "my_macros.h"

// problem 10.4 using dynamic programming

int count(int n){
  int t[1<<n][n];

  // to initialize all entries to zero
  // key
  REP(i, 0, (1<<n)-1)
    REP(j, 0, n-1)
      t[i][j] = 0;

  REP(i, 0, n-1) // f({i}, i)=1
    t[1<<i][i] = 1;
  
  REP(s, 0, (1<<n)-1){
    REP(i, 0, n-1){ // s ending in i
      REP(j, 0, n-1){ // s-{i} ending in j
	if((s&(1<<j)) && (s&(1<<i)) && (abs(i-j)>1))
	  t[s][i] += t[s^(1<<i)][j];
      }
    }
  }
  int r = 0;
  REP(i, 0, n-1)
    r += t[(1<<n)-1][i];
  return r;
}

int main(){
  cout << count(4) << endl;
  return 0;
}
