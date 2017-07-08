#include <iostream>
#include <vector>

using namespace std;

#include "my_macros.h"

int find_smallest_solution(vector<bool> a){
  //return the smallest index i such that a[i] is true
  int k=0;
  for(int b=a.size()/2; b>=1; b/=2){
    while((k+b) < a.size() && !a[k+b]) k+=b;
  }
  if(k == a.size()-1) return -1;
  else if(a[k])       return k;  // 0
  else                return k+1;
}


int main(){
  vector<bool> a1 = {false, false, false, true ,true}, // 3
    a2 = {false, false, false, false ,true}, // 4
      a3 = {false, false, false, false ,false}, // -1
	a4 = {true, true, true, true ,true}; // 0

  cout << "finding smallest solution:" << endl;
  cout << "expecting 3=" << find_smallest_solution(a1) << endl;
  cout << "expecting 4=" << find_smallest_solution(a2) << endl;
  cout << "expecting -1=" << find_smallest_solution(a3) << endl;
  cout << "expecting 0=" << find_smallest_solution(a4) << endl;
}
