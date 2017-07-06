#include <array>
#include <iostream>

using namespace std;

#include "my_macros.h"

/*
   - INT_MIN, INT_MAX
   - library `std::array`, array<type, size> = { {...} };
   - `std::array` as parameter of unknown size, use template, `template<std::size_t SIZE>`
   - syntax: `int x=0, y=0;`
*/

const int n = 100;
array<int, n> input = { {-1, 2, 4, -3, 5, 2, -5, 2} };

template<std::size_t SIZE>
int my_solution(array<int, SIZE> input){
  array<int, SIZE> max_array;
  array<int, SIZE> bp;
  int max_val = INT_MIN;
  int max_ind;

  REP(i, 0, SIZE-1){
    if(i>0 && max_array[i-1] > 0) {
      max_array[i] = input[i] + max_array[i-1];
      bp[i] = i-1;
    }
    else {
      max_array[i] = input[i];
      bp[i] = i;
    }

    if (max_array[i] > max_val){
      max_val = max_array[i];
      max_ind = i;
    }
  }

  int start = -1;
  int end = max_ind;

  while(true){
    if(bp[max_ind] != max_ind){
      max_ind = bp[max_ind];
    }
    else{
      break;
    }
  }
  start = max_ind;

  int s = 0;
  REP(i, start, end){
    // cout << input[i] << endl;	
    s += input[i];
  }
  return s;
}

template<std::size_t SIZE>
int ref_solution(array<int, SIZE> x){
  int m=0, s=0;
  REP(i, 0, SIZE-1){
    s = max(x[i], s + x[i]); // s = best sum ending at i
    m = max(m, s); // m = best sum ever
  }
  return m;
  
}
int main(){
  cout << "sum (my sol) = " <<  my_solution(input) << endl;
  cout << "sum (ref sol) = " << ref_solution(input) << endl;
  return 0;
}
