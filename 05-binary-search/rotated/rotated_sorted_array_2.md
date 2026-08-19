# Search in Rotated Sorted Array II

There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

You must decrease the overall operation steps as much as possible.

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false

# Solution

The trick here is that there are duplicate elements, making it tricky to detect the sorted half.

So, the problem rises when, nums[left] == nums[mid] == nums[right].
simple try to get rid of it.

If that is the case, just after the nums[mid]==target condition, check for the above condition and do a left++, right--

also, add the condition <= and >= in the other below conditions, because duplicates are there.
Since we are handling the edge case above, there shouldn't be a problem.

```cpp
bool search(vector<int>& nums, int target) {
    int n = nums.size(), left = 0, right = n - 1;
    while (left <= right) {
        int mid = right - (right - left) / 2;
        if(nums[mid]==target) return true;
        else if(nums[mid]==nums[left] && nums[mid]==nums[right] && right!=left){
            left++;
            right--;
        }
        else if(nums[mid]>=nums[left]){//left half is sorted
            if(nums[mid]>=target && nums[left]<=target){ // element lies on the left.
                right=mid-1;
            } else{ // element lies in the right, unsorted part
                left=mid+1;
            }
        } else{ // right half is sorted
            if(nums[mid]<=target && nums[right]>=target){ // element lies on the right
                left=mid+1;
            } else{ // element lies in the left, unsorted part
                right=mid-1;
            }
        }
    }
    return false;
}
```
