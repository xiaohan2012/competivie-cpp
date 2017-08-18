#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#include "my_macros.h"

int f1(vector<int> ws, vector<int> vs, int c){
  // using d(k, w)
  int n = ws.size();
  vector<vector<int>> d(n, vector<int>(c+1, 0));
  REP(k, 1, n-1){
    REP(w, 1, c){
      if(w-ws[k] >= 0){
	d[k][w] = d[k-1][w-ws[k]] + vs[k];
      }
      d[k][w] = max(d[k][w], d[k-1][w]);
    }
  }
  return d[n-1][c];
}

int f2(vector<int> ws, vector<int> vs, int c){
  // using d(k, v)
  int n = ws.size();
  int s = 0;
  for(auto v: vs) s+=v;
  vector<vector<int>> d(n, vector<int>(s+1, 100));
  REP(i, 0, n-1) d[i][0] = 0;
  
  REP(k, 1, n-1){
    REP(v, 1, s){
      if(v-vs[k] >= 0)
	d[k][v] = d[k-1][v-vs[k]] + ws[k];
      d[k][v] = min(d[k][v], d[k-1][v]);
    }
  }
  for(int v=s; v>=0; v--){
    if(d[n-1][v] <= c)
      return v;
  }
  return -1;
}

int main(){
  vector<int> ws = {5, 6, 8, 5};
  vector<int> vs = {1, 3, 5, 3};
  cout << f1(ws, vs, 12) << endl;;
  cout << f2(ws, vs, 12) << endl;;
  return 0;
}
