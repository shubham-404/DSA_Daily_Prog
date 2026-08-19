# Split Array Largest Sum
## same as book allocation

Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.

 

Example 1:

Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.

Example 2:

Input: nums = [1,2,3,4,5], k = 2
Output: 9
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.

# Not really brute force, but using Linear Search.

```cpp
// Since sum has to be the minimum of largest sum of subarrays, the smallest possible answer is gonna be the largest element and the largest possible answer is gonna be the sum of all the elements.

```

# More optimized, using BS

```cpp
int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if (k > n)
            return -1;
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while (low <= high) {
            int mid = high - (high - low) / 2;
            int studCount = 1, pageCount = 0;
            for (int i = 0; i < n; i++) {
                if (pageCount + nums[i] <= mid) {
                    pageCount += nums[i];
                } else {
                    pageCount = nums[i];
                    studCount++;
                }
            }
            if (studCount > k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
```
