#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#include "my_macros.h"

int f(string a, string b){
  int m=a.size(), n=b.size();
  vector<vector<int>> d(m+1, vector<int>(n+1, 0));
  REP(i, 0, m){
    d[i][0] = i;
  }
  REP(j, 0, n){
    d[0][j] = j;
  }
  
  REP(i, 1, m){
    REP(j, 1, n){
      d[i][j] = min({d[i-1][j] + 1,
	    d[i][j-1] + 1,
	    d[i-1][j-1] + (a[i-1] == b[j-1] ? 0:1)});
    } 
  }
  return d[m][n];
}

int main(){
  string a="love", b="movie";
  cout << f(a, b) << endl;
  return 0;
}
