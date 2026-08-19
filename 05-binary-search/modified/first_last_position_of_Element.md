# Find First and Last Position of Element in Sorted Array

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]

# Solution
To be implemented using concepts of lower bound and upper bound problems.
- make changes in the lower bound problem's solution to return -1, if element not found.
- also update it to mind the fact of element being found. earlier it was using >= or <= condition, change it to find the equal element to the target and make change in the ans variable.


```cpp
int lowerBound(vector<int>& arr, int n, int target) {
        if (n == 0)
            return -1;
        if (n == 1 && arr[0] == target)
            return 0;
        if (target > arr[n - 1])
            return -1;
        int left = 0, right = n - 1, ans = n; // ans=INT_MAX also works
        bool found = false;
        while (left <= right) {
            int mid = right - (right - left) / 2;
            if (arr[mid] > target) {
                right = mid - 1;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                found = true;
                ans = min(ans, mid);
                right = mid - 1;
            }
        }
        if (!found)
            return -1;
        return ans;
    }

    int upperBound(vector<int>& arr, int n, int target) {
        if (n == 0)
            return -1;
        if (n == 1 && arr[0] == target)
            return 0;
        if (target > arr[n - 1])
            return -1;
        int left = 0, right = n - 1, ans = -1;
        while (left <= right) {
            int mid = right - (right - left) / 2;
            if (arr[mid] > target) {
                right = mid - 1;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                ans = max(ans, mid);
                left = mid + 1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int lb = lowerBound(nums, n, target);
        int ub = upperBound(nums, n, target);
        vector<int> ans;
        ans.push_back(lb);
        ans.push_back(ub);
        return ans;
    }
```