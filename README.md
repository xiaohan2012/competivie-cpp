# maximum subarray sum

- `INT_MIN`, `INT_MAX`
- syntax: `int x=0, y=0;`

- library `std::array`, array<type, size> = { {...} };
- `std::array` as parameter of unknown size, use template, `template<std::size_t SIZE>`

- much easier solution for maximum subarray sum

# sort and binary search

- `makefile`: use `CXX` instead of `CC`for cpp programs (similar for `CPPFLAGS`)
- sort `vector` using `sort`, `.begin() and `.end()`. `rbegin()` and `rend()`
- syntax: `template<typename T> void swap(T& x, T& y)`
- print vector not very handy in C++, needs to write your own function
- `std:pair` usage, `first` and `second`
- `std:get<i>(tuple)` to get the `i`th element, works also for `pair`
- external `cmp` function

- use `lower_bound` as binary search
- use `upper_bound` as index + 1
- to get the index, use `index - v.begin()`

## 2nd version of binary search based on jump

- jump: another method to search (also logarithmic time)
  - `k`: current position
  - `b`: stride to try with `k+b`. 
    - if fail, then try smaller stride (`b/=2`)
- integer division like Python: `5/2 = 2`
- generalization of the jump binary search on finding smallest solution with on arrays like `<F, F, F, F, T, T, T>`


# data structures

## vector
- `vector<type> a(length, value)` or `vector<type> a(length)` initialized all to zero
- `.back` and `.front` method

## string

- `substr` and `find`

## set

- `set` based on balanced binary tree, `O(log n)` time
- `unordered_set` based on hashtable, `O(1)` time

main methods: `insert`, `erase`, `count` (can be used as contains)


- similarly for `multiset` and `unordered_multiset`


## map

- similarly `map` and `unordered_map`
- insertion by `m[key]=value`
- existence by `m.count(key)`
- if a key does not exist but is requested, automatically added with default value
- `for(auto p: m)` and `p.first` and `p.second` (`p` is a pair)

## iterators

- iterating vector, set, string using `iterators`
- an iterator is essentially a pointer
- `s.begin()` returns a pointer. so to get the value, use `*` to de-reference

## bitset
- `cout << (s1 & s2) << endl;` using *parenthesis* s1 and s2
- `bitset<10> bs(string("0101010"))`
- if length is longer, the zeros are *prepended*

## deque

- change on *both* ends of the list
- `push_{front|back}` and `pop_{front|back}`
- comparison to `vector`: `push_front` and `pop_front` not supported

## stack

- `push`, `top` and `pop`

## queue

- `push`, `front` and `pop`

## `priority_queue`

- `push`, `top` and `pop`
- sorted from largset to smallest by default
- `priority_queue<int> q;`
- `priority_queue<int,vector<int>,greater<int>> q;`: from smallest to greatest

# complete search

## generating subset

- method 1: review of recursive method
- method 2: each subset can be represented by a bitset of size `n`
  - so we iterate through an int varaible `b` from `0` to `(1<<n) - 1` (for example, if `n=3`, then `b` is from `000` to `111`
  - to check if the `i`th bit is active, use `(1<<i) & b` (neat!)


## permutation

- method 1: recursive
  - selecting the `i`the number a the starting code and recurse on the rest of the sequence
- method 2: `next_permutation`

## backtracking

a technique featured by:

- *incrementally* build a solution
- abandons a partial solution if not feasible ("backtrack" means "go back")


"queen" problem: solved by recursive approach

- a novel way to store which position is possible/impossible
  - cells in the same column share the same column index
  - cells in the same left diagonal share the same `x+y` value
  - similar results for cells in the right diagonal
  - kinda of "common features" for linked cells
  - the storage is **linear** instead of quadratic (wow!)

# pruning

- 2d vector, example: `vector<vector<bool>> m(d, vector<bool>(d, false))`
- [print stacktrace](https://stackoverflow.com/questions/18706496/can-one-use-libsegfault-so-to-get-backtraces-for-sigabrt) or [this for C](https://stackoverflow.com/questions/77005/how-to-generate-a-stacktrace-when-my-gcc-c-app-crashes)
- tool gdb: `run` and `where` to print stacktrace
- one cause for *segmentatio fault*: recursion does not terminate

# dynamic programming

- use `min/max` function to update
- problem: path in a grid, initial state for first row and column
- initialize 2d vectors with values: `vector<vector<int>> m {{...}, ..., {...}}
- running time of dp for knapsack: `O(nW)` or `O(nS)`
  - `W` capacity
  - `S` sum of values of all items
  - [pseudo-polynomial](https://en.wikipedia.org/wiki/Pseudo-polynomial_time): running time in the *numeric value* of the input (not size)

## string edit distance

dynamic programing table index 0 and array index 0 -- different meaning

- table index 0: empty string
- array index 0: the first character
- use `min({num1, ..., numk})` for a list of numbers

- `(expr1 opr expr2 ? val1 : val2))`