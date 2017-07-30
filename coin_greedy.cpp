#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#include "my_macros.h"

vector<int> get_coins(vector<int> cs, int s){
  int t = 0;
  vector<int> a;
  while(t != s){
    for(auto c: cs){
      if(t+c <= s){
	t += c;
	a.push_back(c);
	break;
      }
    }
  }
  return a;
}
int main(){
  vector<int> c = {{1, 2, 5, 10, 20, 50, 100, 200}};

  sort(c.rbegin(), c.rend());
  print_vector(c);
    
  cout << "target: 520" << endl;
  print_vector(get_coins(c, 520));

  cout << "target: 99" << endl;
  print_vector(get_coins(c, 99));
  return 0;
}
