#include <iostream>
#include <vector>

using namespace std;

#include "my_macros.h"

int path_count(int x, int y, int d, vector<vector<bool>> m, int t){
  int c = 0;

  // OK!
  if(x == d-1 && y == d-1 && t == d*d)
    return 1;

  // in the corner, not all finished
  if(x == d-1 && y == d-1 && t < d * d)
    return 0;

  // out of bound
  if(x < 0 || y < 0 || x >= d || y >= d)
     return 0;

  /// optimization 3
  if((x == 0 || m[x-1][y]) && // cannot go left
     (x == d-1 || m[x+1][y]) &&  // cannot go right
     (y > 0 && !m[x][y-1]) && // can go down
     (y < d-1 && !m[x][y+1])) // can go up
    return 0;

  // vice versa
  if((y == 0 || m[x][y-1]) && // cannot go up
     (y == d-1 || m[x][y+1]) &&  // cannot go down
     (x > 0 && !m[x-1][y]) && // can go left
     (x < d-1 && !m[x+1][y])) // can go right
    return 0;
  
  vector<int> p = {{-1, 1}};
  for(auto i: p){
    if(x+i >= 0 && x+i < d && !m[x+i][y]){ // move left or right
      m[x+i][y] = true;
      c += path_count(x+i, y, d, m, t+1);
      m[x+i][y] = false;
    }

    if(y+i >= 0 && y+i < d && !m[x][y+i]){ // move up or down
      m[x][y+i] = true;
      c += path_count(x, y+i, d, m, t+1);
      m[x][y+i] = false;
    }
  }
  return c;
}

int main(){
  const int d = 7;
  vector<vector<bool>> m(d, vector<bool>(d, false));
  m[0][0] = m[0][1] = true;
  cout << 2 * path_count((int)0, (int)1, d, m, 2) << endl;
  return 0;
}
