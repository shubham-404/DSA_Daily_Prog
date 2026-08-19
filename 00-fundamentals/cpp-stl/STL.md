# Containers

## Vectors

- Array is fixed size, vectors are dynamic sized, can be changed in run time.

    ```cpp
    vector<int> vec; // vec.size() => 0
    ```

- vec.push_back(1); // insert at end.
- vec.emplace_back(9); // insert at end, inplace, more efficient ig.
- vec.pop_back(); // remove last element
- vec.push_back(12); // since, initial size was 1, a new address is allocated double the size and the previous elements are copied and new element is inserted making the size 2.
- vec.size(); // no. of elements in the vector
- vec.capacity(); // no. of elements vector can hold. 

- forEach LOOP
    ```cpp
    for(int val: vec){
        cout << val << " " ;
    }
    ```

- vec[ind] <=> vec.at(ind)
- vec.front() // first element
- vec.back() // last element
- vector<int> vec = {1, 2, 3, 4};
- vector<int> vec(3, 10); // [10, 10, 10] -> used in dp
- vec<int> vec1(vec);  // shallow copy - shared memory

// *All above functions work in O(1).

- vec.erase(vec.begin()+2); // deletes index 2 - takes iterator and works in O(n);
- vec.erase(start, end); // [start, end)**

- vec.insert(pos_itr, val);
- vec.clear(); // changes the size not capacity.
- vec.empty(); // returns 1/0

- iterators -> vec.begin() and vec.end() -> returns the address of first element, and next to last element.
- use dereferencing operator *(vec.begin()) gives value.
- vec.end() -> garbage value (next to last).

## List
- implements doubly linked list.
    ```cpp
    #include <list>
    list<int> l;
    l.push_back(1);
    l.push_front(3);
    l.pop_back();
    l.pop_front();
    // random value accessing is NOT possible.
    ```

## Deque
- implements double ended queue using dynamic array.
    ```cpp
    #include <deque>
    // very similar to list.
    // random value accessing is possible.
    ```

## Pair
- can pair up any two values of any data type.
    ```cpp
    vector<pair<int, string>> p1 = {{1, "hello"}, {2, "lelo"}};
    cout << p1[0].first <<" "<< p1[0].second;
    p1.push_back({4, "s4"});
    p1.emplace_back(4, "s4"); // creates in-place object
    ```

## Stack - LIFO 
    ```cpp
    #include<stack>
    stack<int> stk;
    stk.push(1);
    stk.emplace(2);
    while(!stk.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    // you can also swap two stacks using s2.swap(s1); 
    ```

## Queue - FIFO
    - same functions as stack.

## Priority Queue
- Internally implements maxHeap/minHeap.
- by default, priority is given to larges element, so poping gives increasing order.
```cpp
    #include <queque>
    priority_queue<int> q1; // operations same as queue
    // organizes elements in sorted order (descending by defalut)
    priority_queue<int, vector<int>, greater<int>> /*functor*/ q2;
    // organizes elements in ascending order

```

## Map
- map<string, int> mp;
- mp[key] = value;
```cpp
#include<map>
map<string, int> mp;
mp["tv"] = 30000;
mp["fridge"] = 25000;
mp["iphone"] = 130000;
for(auto i:mp){
    cout << i.first << " " i.second << endl;
}
//also print in lexicographically ascending order!
```

## Multi-Map
- map<string, int> mp;
- // not allowed like this: mp[key] = value;
- use operations like insert and find.
- find returns iterator if found, or returns mp.end();
```cpp
#include<map>
multi_map<string, int> mp; 
mp["tv"] = 30000;
mp["tv"] = 25000;
mp["iphone"] = 130000;
for(auto i:mp){
    cout << i.first << " " i.second << endl;
}
```

## Unordered-Map
- mp[key] = value;
```cpp
#include<unordered_map>
unordered_map<string, int> mp;
mp["tv"] = 30000;
mp["fridge"] = 25000;
mp["iphone"] = 130000;
for(auto i:mp){
    cout << i.first << " " i.second << endl;
}
```

## Set
- stores only unique values.
- // methods same as above, insert, emplace, count, erase, find, size, empty.


# Iterators
## lower_bound
- Returns an iterator, can be accessed with *(itr).
- If the value exists in the range: It returns an iterator to the first occurrence of that value. 
- If the value does not exist in the range: It returns an iterator to the first element that is strictly greater than the specified value. 
- If all elements in the range are less than the specified value: It returns an iterator to the end() of the range.
```cpp

```
# Algorithms
# Functors
