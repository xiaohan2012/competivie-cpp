#include <iostream>
#include <vector>

using namespace std;

#include "my_macros.h"

int bs(vector<int> a, int x){
  int i=0, j=a.size()-1;
  while(i<=j){
    int k=(i+j)/2;
    if(a[k] == x) return k;
    else if(a[k] < x) i=k+1;
    else j=k-1;
  }
  return -1;
}

int main(){
  vector<int> a = {4, 1, 2, 0, 5, 0, 9, 1};
  sort(a.begin(), a.end());
  
  print_vector(a);
  
  cout << "position of 4: " << bs(a, 4) << endl;
  cout << "position of 9: " << bs(a, 9) << endl;

  cout << "position of 4 (lb): " << (lower_bound(a.begin(), a.end(), 4) - a.begin()) << endl;
  cout << "position of 9 (lb): " << (lower_bound(a.begin(), a.end(), 9) - a.begin()) << endl;

  cout << "position of 4 (ub): " << (upper_bound(a.begin(), a.end(), 4) - a.begin()) << endl;
  cout << "position of 9 (ub, not found): " << (upper_bound(a.begin(), a.end(), 9) - a.begin()) << endl;
  return 0;
}
