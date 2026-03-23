Max Consecutive Ones III

Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

Example 2:

Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

# Solution

```cpp
int longestOnes(vector<int>& nums, int k) {
    int n = nums.size(), zeroes = 0, maxOnes = 0;
    int left = 0;
    for (int right = 0; right < n; right++) {
        // 1. expand window
        // include nums[right]
        if (zeroes <= k) {
            if (nums[right] == 0) {
                zeroes++;
            }
            // maxOnes = max(maxOnes, right - left + 1);
        }

        // 2. fix the window
        while (zeroes > k) {
            if (nums[left] == 0) {
                zeroes--;
            }
            left++;
        }

        // 3. update answer
        maxOnes = max(maxOnes, right - left + 1);
    }
    return maxOnes;
}
```
