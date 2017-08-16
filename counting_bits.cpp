#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

#include "my_macros.h"

#include <math.h>

vector<int> countBits(int num) {
  vector<int> r(num+1, 0);
  for(int i=0; i<=num; i++){
    if(i<=1){
      r[i] = i;
      continue;
                  
    }
    int e = (int)log2(i);
    int d = (int)pow(2, e-1);
    r[i] = r[i-d];
    if(i&(1<<(e-1))) // (e-1)th bit
      r[i] += 1;
            
  }
  return r;
}

int main(){
  print_vector(countBits(5));
  print_vector(countBits(8));
  return 0;
}
