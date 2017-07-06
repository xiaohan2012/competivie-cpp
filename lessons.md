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

