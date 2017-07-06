#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

#include "my_macros.h"

bool cmp_str(string a, string b){
  // shorter string is always < 
  if(a.size() != b.size()){
    return a.size() < b.size();
  }
  return a < b;
}

int main(){
  // sort vector of int
  vector<int> v = {3, 4, 1, 5, 2};
  sort(v.begin(), v.end());  
  print_vector(v);

  sort(v.rbegin(), v.rend());  
  print_vector(v);

  int a[v.size()];
  REP(i, 0, v.size()-1){
    a[i] = v[i];
  }
  sort(a, a+v.size());
  
  REP(i, 0, v.size()-1){
    cout << a[i] << " ";
  }
  cout << endl;

  /*
  unable to sort backward
  sort(s+v.size(), s);
  
  REP(i, 0, v.size()-1){
    cout << s[i] << " ";
  }
  cout << endl;
  */

  // sort char array
  string s = "der";
  sort(s.rbegin(), s.rend());
  cout << s << endl;

  // vector of tuple

  vector<pair<int, int>> ps;
  ps.push_back({1, 2});
  ps.push_back({1, 1});
  ps.push_back({3, 2});
  ps.push_back({2, 4});
  sort(ps.begin(), ps.end());

  cout << "sorting pairs: ";
  for(auto p: ps){
    cout << "(" << p.first << " " << p.second << "), ";
  }
  cout << endl;


  // vector of tuple
  vector<tuple<string, int, int>> ts;
  ts.push_back(make_tuple("first", 1, 2));
  ts.push_back(make_tuple("second", 1, 1));
  ts.push_back(make_tuple("third", 3, 2));
  ts.push_back(make_tuple("fourth", 2, 4));
  sort(ts.begin(), ts.end());

  cout << "sorting tuples: ";
  for(auto t: ts){
    cout << "(" << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << "), ";
  }
  cout << endl;

  // custom `cmp` function
  vector<string> ss = {"b", "bb", "bbb", "ab", "bbbb"};
  sort(ss.begin(), ss.end(), cmp_str);
  cout << "sorting vector of strings using custom cmp function: ";
  print_vector(ss);
  return 0;
}
