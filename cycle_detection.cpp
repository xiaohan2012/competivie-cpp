#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <tuple>

using namespace std;

#include "my_macros.h"

bool has_cycle(vector<vector<int>> g, int s){
  stack<pair<int, int>> q;
  vector<bool> z(g.size(), false); // g is a pointer

  q.push({-1, s});
  z[s] = true;

  int prev, i;
  while(q.size() > 0) {
    tie(prev, i) = q.top();    q.pop();
    cout << "visiting " << i << endl;
    for(auto j: g[i]){
      if(!z[j]) {
	z[j] = true;
	q.push({i, j});
      }
      else if((j != prev) && (prev != -1))
	return true;
    }
  }
  return false;
}


int main(){
  int n = 6;
  vector<vector<int>> g(n, vector<int>());
  vector<pair<int, int>> edges {{1, 3}, {2, 3}, {2, 5}, {3, 5}, {1, 4}, {3, 4}};
  for(auto e: edges){
    int i = e.first, j = e.second;
    g[i].push_back(j);
    g[j].push_back(i); 
  }

  cout << "has cycle? " << has_cycle(g, 1) << endl;

  vector<vector<int>> g1(5, vector<int>());
  edges = {{1, 2}, {1, 3}, {3, 4}};
  for(auto e: edges){
    int i = e.first, j = e.second;
    g1[i].push_back(j);
    g1[j].push_back(i); 
  }

  cout << "has cycle? " << has_cycle(g1, 1) << endl;  
  return 0;
}
