# Problem
Given an array `nums` of integers, return all the triplets as array, such that `nums[i] + nums[j] + nums[k] = 0` and `i!=j`, `j!=k`, `i!=k`

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.


Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.


Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
 

Constraints:
3 <= nums.length <= 3000
-105 <= nums[i] <= 105


# Solution
The approach is simple. for each element, find the pair of remaining two, using Two Sum-II (sorted array), so that the required sum is achieved.
Except there is a catch. the elements can repeat in the input array. 
To get rid of that, we will sort the input array, and skip the repeated elements.

```cpp
vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int left = i + 1, right = n - 1;
            while (left < right) {

                int threeSum = nums[i] + nums[left] + nums[right];
                if (threeSum > 0)
                    right--;
                else if (threeSum < 0)
                    left++;
                else { // found triplets
                    ans.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    while (left < right && nums[right] == nums[right - 1])
                        right--;
                    // now the next element of left is not equal
                    // now the previous element of right in also not equal
                    left++;
                    right--;
                }
            }
        }
        return ans;
    }

```
