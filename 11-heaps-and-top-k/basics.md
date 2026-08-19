# Binary heap is essentially a _Balance Binary Tree_ and is of two types;

- Min Heap - parent node is smaller than the left, right, root is smallest
- Max Heap - parent node is greater than the left, right, root is largest

> It is interestingly implemented using arrays with the index of parent being `(i-1)/2 th` index, and index of the left child `2*i+1` and that of right child `2*i+2`.
> Index of the root node is `0`.

```
        MAX HEAP
            9
           / \
          8   7
         / \  / \
        6  5  4  3
       / \
      2   1

      [9, 8, 7, 6, 5, 4, 3, 2, 1]
       0  1  2  3  4  5  6  7  8   <= indices
```

## Operations on a heap

- Insert()
- Heapify()
- getMin()
- ExtractMin()
- Delete()
- DecreaseKey()

## Time complexities

- Insert() - `O(logN)`
- Heapify() - `O(logN)`
- getMin() - `O(1)`
- ExtractMin() - `O(logN)`
- Delete() - `O(logN)`
- DecreaseKey() - `O(logN)`
