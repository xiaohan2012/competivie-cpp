#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#include "my_macros.h"

class NumArray {
private:
  int n;
  vector<int> sums;
public:
  NumArray(vector<int> nums): n(nums.size()), sums(n, 0) {
    if(n==0) return;
    sums[0] = nums[0];
    for(int i=1; i<n; i++){
      sums[i] = nums[i] + sums[i-1];              
    }
    print_vector(sums);
  }

  int sumRange(int i, int j) {
    if(i>j || i<0 || j>=n) return 0;

    if(i==0)
      return sums[j];
    else
      return sums[j] - sums[i-1];
        
  }
  
};

int main(){
  vector<int> nums = {-2,0,3,-5,2,-1};
  NumArray a = NumArray(nums);
  cout << a.sumRange(0, 2) << endl;
  return 0;
}
