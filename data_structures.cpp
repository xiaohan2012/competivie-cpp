#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

#include "my_macros.h"

int main(){
  cout << "vector:" << endl;
  vector<int> v1(5, 1);
  print_vector(v1);
  v1[0] = 0;
  v1[4] = 4;
  cout << "v1.front()=" << v1.front() << endl;
  cout << "v1.back()=" << v1.back() << endl;
  cout << endl;

  cout << "string:" << endl;
  string s = "fengder";
  cout << "substring: " << s.substr(s.find("d"), 3) << endl;
  cout << endl;  

  cout << "set: " << endl;
  set<int> s1 = {1,2,3};
  cout << "1 in set? " << s1.count(1) << endl;
  cout << "5 in set? " << s1.count(5) << endl;

  s1.insert(5);
  s1.erase(1);

  cout << "1 in set? " << s1.count(1) << endl;
  cout << "5 in set? " << s1.count(5) << endl;
  cout << endl;  

  cout << "map: " << endl;
  map<int, string> m;
  m[1] = "one";
  m[2] = "two";
  cout << "m[1]=" << m[1] << endl;
  cout << "3 in m?" << m.count(3) << endl;
  cout << "m[3] (does not exist, automatically added)=" << m[3] << endl; 
  cout << "3 in m?" << m.count(3) << endl;
  for(auto p: m)
    cout << p.first << " -> " <<p.second << endl;
  cout << endl;    

  cout << "iterators: " << endl;
  sort(v1.begin(), v1.end());

  cout << "after sorting" << endl;
  print_vector(v1);

  reverse(v1.begin(), v1.end());
  cout << "after reversing" << endl;
  print_vector(v1);

  random_shuffle(v1.begin(), v1.end());
  cout << "after random shuffling" << endl;
  print_vector(v1);

  auto p = s.begin();
  cout << "s.begin() de-referenced: " << *p << endl;
  cout << "p++ de-referenced: " << *(++p) << endl;  

  cout << "iterating through string using iterators" << endl;
  for(auto p=s.begin(); p<s.end(); p++){
    cout << *p << " ";
  }
  cout << endl;

  
  cout << "bitset: " << endl;
  bitset<10> bs1(string("1010101"));
  bitset<10> bs2(string("0001111"));
  cout << (bs1 & bs2) << endl;
  cout << (bs1 | bs2) << endl;
  cout << (bs1 ^ bs2) << endl;
  
  cout << endl;

  cout << "deque: " << endl;
  
  return 0;
}
