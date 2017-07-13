#include <iostream>
#include <vector>

using namespace std;

#include "my_macros.h"

void gen1(vector<int> ref_v, vector<int> v, int k){
  if(k==ref_v.size()){
    print_vector(v);
  }
  else{
    v.push_back(ref_v[k]);
    gen1(ref_v, v, k+1);
    
    v.pop_back();
    gen1(ref_v, v, k+1);
  }
}

void gen2(vector<int> ref_v){
  REP(b, 0, (1 << ref_v.size()) - 1){
    vector<int> v;
    REP(i, 0, ref_v.size()-1){
      if(b & (1 << i)) 
	v.push_back(ref_v[i]);
    }
    print_vector(v);
  }
}

int main(){
  vector<int> ref_v = {0,1,2}, v;  
  cout << "method 1" << endl;
  gen1(ref_v, v, 0);

  cout << "method 2" << endl;
  gen2(ref_v);
}
