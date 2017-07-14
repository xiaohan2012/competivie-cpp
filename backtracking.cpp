#include <iostream>
#include <vector>

using namespace std;

#include "my_macros.h"

void queen(int y, int n, vector<int> r1, vector<int> r2, vector<int> r3, int& c){
  if(y == n){
    c++;
  }
  else{
    REP(x, 0, n-1){
      if(r1[x] || r2[x+y] || r3[x-y+n-1]) continue;
      r1[x] = r2[x+y] = r3[x-y+n-1] = 1;
      queen(y+1, n, r1, r2, r3, c);
      r1[x] = r2[x+y] = r3[x-y+n-1] = 0;
    }
  }
}

int main(){
  int n = 4, c=0;
  queen(0, n,
	vector<int> (n, 0),
	vector<int>(2*n-2, 0),
	vector<int>(2*n-2, 0),
	c);
  cout << c << endl;

  n=8; c=0;
  queen(0, n,
	vector<int> (n, 0),
	vector<int>(2*n-2, 0),
	vector<int>(2*n-2, 0),
	c);
  cout << c << endl;
  return 0;
}
