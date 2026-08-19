# Search Insert Position

Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

# Solution
Implementation similar to lower bound problem.

```cpp
int searchInsert(vector<int>& nums, int target) {
        int n = nums.size(), left = 0, right = n - 1;
        if(target>nums[right]) return n;
        if(target<nums[left]) return 0;
        while (left <= right) {
            int mid = right - (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
            if (target < nums[left])
                return left;
            if (target > nums[right])
                return mid;
        }
        return -1;
    }
```