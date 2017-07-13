#include <iostream>
#include <vector>

using namespace std;

#include "my_macros.h"

void permutation(vector<int> ref_v, vector<int> v, vector<bool> p){

  if(v.size() == ref_v.size()) print_vector(v);
  else {
    REP(i, 0, ref_v.size()-1){
      if(p[i]) continue;

      p[i] = true;
      v.push_back(ref_v[i]);

      permutation(ref_v, v, p);

      p[i] = false;
      v.pop_back();
    }
  }
}

int main(){
  vector<int> ref_v = {1,2,3}, v;
  vector<bool> p(ref_v.size(), false);
  permutation(ref_v, v, p);
  
  cout << "easier way: " << endl;
  vector<int> v2;
  for(auto i: ref_v){
    v2.push_back(i);
  }
  do{
    print_vector(v2);
  }
  while(next_permutation(v2.begin(), v2.end()));
}
