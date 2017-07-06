#define REP(i, a, b) for(int i=a; i <= b; i++)

template<typename t>
void print_vector(vector<t> v){
  for(auto i: v){
    cout << i << " ";
  }
  cout << endl;
}


template<typename t1, typename t2>
void print_vector_pairs(vector<pair<t1, t2>> v){
  for(auto i: v){
    cout << i << " ";
  }
  cout << endl;
}
