#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#include "my_macros.h"

int f(vector<vector<int>> g, int r, int c){
  vector<vector<int>> d(r, vector<int>(c, 0));
  d[0][0] = g[0][0];
  REP(i, 1, r-1){
    d[i][0] = d[i-1][0] + g[i][0];
  }
  REP(j, 1, c-1){
    d[0][j] = d[0][j-1] + g[0][j];
  }

  REP(i, 1, r-1){
    REP(j, 1, c-1){
      if(d[i][j-1] == 0 || d[i-1][j] == 0){
	cout << "some entry is zero" << endl;
      }
      d[i][j] = max(d[i][j-1], d[i-1][j]) + g[i][j];
    }
  }
  return d[r-1][c-1];
}
int main(){
  vector<vector<int>> g{
    {3, 7, 9, 2, 7},
      {9, 8, 3, 5, 5},
	{1, 7, 9, 8, 5},
	  {3, 8, 6, 4, 10},
	    {6, 3, 9, 7, 8}};
  int r=5, c=5;

  cout << "actual: " << f(g, r, c) << endl;
  cout << "expected: " << 3 + 9 + 8 + 7 + 9 + 8 + 5 + 10 + 8 << endl;
  // cout << g[3][4] << endl;
  // cout << g[4][3] << endl;
  return 0;
}
