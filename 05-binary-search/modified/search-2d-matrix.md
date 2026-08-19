# Problem
## Search a 2D Matrix

You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity

# Solution
Applying binary search, while traversing.
what i came up with is linear search in rows and binary search in cols, not the best way but it worked.

```cpp

bool binSearch(vector<int> arr, int n, int target){
        int low = 0, high = n - 1, mid;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (arr[mid] == target)
                return true;
            else if (arr[mid] > target)
                high = mid - 1;
            else if (arr[mid] < target)
                low = mid + 1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        if(rows == 1) return binSearch(matrix[0], cols, target);
        int i = 1;
        while (i < rows) {
            if(matrix[i][0] > target){
                return binSearch(matrix[i-1], cols, target);
            }
            i++;
            if(i==rows) return binSearch(matrix[i-1], cols, target);

        }
        return false;
    }
```

