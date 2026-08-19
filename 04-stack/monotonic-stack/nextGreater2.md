# Next Greater Element II

Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

Example 1:

Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2;
The number 2 can't find next greater number.
The second 1's next greater number needs to search circularly, which is also 2.

Example 2:

Input: nums = [1,2,3,4,3]
Output: [2,3,4,-1,4]

### The key idea is that we are supposed to know the next as well as the previous elements in this case. So we must use a circular array approach.

# Solution 1

The traditional approach is `Solution 2`, which uses a circular array approach, but this is what I came up with, well, almost on my own. It simulates the same thing but differently and is non-standard.

Store all the elements in reverse in a stack, then, again traverse the array in reverse to see if a NGE is there in teh stack and push, pop accordingly.

```cpp
vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    stack<int> stk;
    vector<int> ans(n, -1);

    // preload stack for circular behavior
    for (int i = n - 1; i >= 0; i--) {
        stk.push(nums[i]);
    }

    for (int i = n-1; i>=0; i--) {
        while (!stk.empty() && stk.top() <= nums[i]) {
            stk.pop();
        }

        if (stk.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = stk.top();
        }

        stk.push(nums[i]);
    }

    return ans;
}
```

# Solution 2

This approach uses circular array approach is standard solution for the NGE problem.

```cpp
vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, -1);
    stack<int> stk;

    for (int i = 2 * n - 1; i >= 0; i--) {
        int idx = i % n;

        while (!stk.empty() && stk.top() <= nums[idx]) {
            stk.pop();
        }

        if (i < n && !stk.empty()) {
            ans[idx] = stk.top();
        }

        stk.push(nums[idx]);
    }

    return ans;
}
```
