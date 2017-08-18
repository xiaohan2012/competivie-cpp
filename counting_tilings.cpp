#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

#include "my_macros.h"

typedef pair<int, string> key;

vector<string> cartesian_product(vector<string> vs, int i, int n){
  // spent me a lot of time
  if(i == 1){
    return vector<string> {"u", "n", "l"};  // no "r"
  }{
    vector<string> r;
    vector<string> p = cartesian_product(vs, i-1, n);
    vector<string> bs;

    for(auto s: p){
      if(s.substr(0, 1) == "l")
	r.push_back("r" + s);
      else{
	if(i == n)
	  bs = {"u", "n"};
	else
	  bs = {"u", "n", "l"};
	for(auto b: bs)
	  r.push_back(b + s);
      }
    }      
    return r;
  }
}

int f(vector<string> a, int r, int c) {
  map<key, int> d;

  for(auto s: a) {
    d[key(1, s)] = ((s.find("u") == string::npos) ? 1 : 0);
  }

  REP(i, 2, r) {
    for(auto ls: a){ // lower row
      d[key(i, ls)] = 0;
      for(auto us: a){ // upper row
	int f = 1;
	REP(j, 0, c-1){
	  string uc = us.substr(j, 1), lc = ls.substr(j, 1);
	  if((uc == "n" && lc != "u") ||
	     (lc == "u" && uc != "n") ||
	     (i == r && ls == "n")){ // last row
	    f = 0;  // incompatible
	    break;
	  }
	}
	
	if(f == 1)
	  d[key(i, ls)] += d[key(i-1, us)];
      }
    }
  }

  int t = 0;
  for(auto s: a) {
    t += d[key(r, s)];
  }
  return t;
}

int main(){
  vector<string> vs = {"u", "n", "l", "r"};
  int r=4, c=7;
  vector<string> a = cartesian_product(vs, c, c);
  // print_vector(a);
  cout << f(a, r, c) << endl;
  return 0;
}
