#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

#include "my_macros.h"

void dfs(vector<int> g[], vector<bool> &z, int i){
  if(z[i]) return;
  cout << "visiting " << i << endl;
  z[i] = true;
  for(auto j: g[i])
    dfs(g, z, j);
}

void dfs1(vector<int> g[], int s){
  stack<int> q;
  vector<bool> z(g->size(), false); // g is a pointer
  q.push(s);
  z[s] = true;

  while(q.size() > 0) {
    int i = q.top();    q.pop();
    cout << "visiting " << i << endl;
    for(auto j: g[i])
      if(!z[j]) {
	z[j] = true;
	q.push(j);
      }
  }
}


void bfs(vector<int> g[], int s){
  queue<int> q;
  vector<bool> z(g->size(), false); // g is a pointer
  q.push(s);
  z[s] = true;

  while(q.size() > 0){
    int i = q.front();    q.pop();
    cout << "visiting " << i << endl;
    for(auto j: g[i])
      if(!z[j]) {
	q.push(j);
	z[j] = true;
      }
  }
}
  
int main(){
  int n = 6;
  vector<int> g[n];
  vector<pair<int, int>> edges {{1, 2}, {2, 3}, {3, 5}, {2, 5}, {1, 4}};
  for(auto e: edges){
    int i = e.first, j = e.second;
    g[i].push_back(j);
    g[j].push_back(i); 
  }
  vector<bool> z(n, false);

  cout << "dfs (recursive):" << endl;
  dfs(g, z, 1);

  cout << "dfs (non-recursive):" << endl;
  dfs1(g, 1);

  cout << "bfs (non-recursive):" << endl;
  bfs(g, 1);  
  return 0;
}
