# Sum of Subarray Ranges

You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.

Return the sum of all subarray ranges of nums.

A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:

Input: nums = [1,2,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0
[2], range = 2 - 2 = 0
[3], range = 3 - 3 = 0
[1,2], range = 2 - 1 = 1
[2,3], range = 3 - 2 = 1
[1,2,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.

Example 2:

Input: nums = [1,3,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0
[3], range = 3 - 3 = 0
[3], range = 3 - 3 = 0
[1,3], range = 3 - 1 = 2
[3,3], range = 3 - 3 = 0
[1,3,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 2 + 0 + 2 = 4.

Example 3:

Input: nums = [4,-2,-3,4,1]
Output: 59
Explanation: The sum of all subarray ranges of nums is 59.

# Solution

No need to get overwhelmed by the code. simply its NGE, PGEE, NSE, PSEE, subarraySumMin and subarrySumMax all combined in.
If we don't use this, there is no other way to solve this question except traversing for O(N2).

```cpp
class Solution {
public:
    // brute force: O(n2);
    // optimal: using sum of subarray maximum and sum of subarray minimum,
    // its easier. next smaller element
    vector<int> findNSE(const vector<int>& arr) {
        int n = arr.size();
        stack<int> stk;
        vector<int> nse(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && arr[stk.top()] >= arr[i]) {
                stk.pop();
            }
            nse[i] = !stk.empty() ? stk.top() : n;

            stk.push(i);
        }
        return nse;
    }
    vector<int> findNGE(const vector<int>& arr) {
        int n = arr.size();
        stack<int> stk;
        vector<int> nge(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && arr[stk.top()] <= arr[i]) {
                stk.pop();
            }
            nge[i] = !stk.empty() ? stk.top() : n;

            stk.push(i);
        }
        return nge;
    }


    vector<int> findPSEE(const vector<int>& arr) {
        int n = arr.size();
        stack<int> stk;
        vector<int> psee(n);
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && arr[stk.top()] > arr[i]) {
                stk.pop();
            }
            psee[i] = !stk.empty() ? stk.top() : -1;

            stk.push(i);
        }
        return psee;
    }
    vector<int> findPGEE(const vector<int>& arr) {
        int n = arr.size();
        stack<int> stk;
        vector<int> pgee(n);
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && arr[stk.top()] < arr[i]) {
                stk.pop();
            }
            pgee[i] = !stk.empty() ? stk.top() : -1;

            stk.push(i);
        }
        return pgee;
    }

    long long sumSubarrayMins(vector<int>& arr) {
        int ans = 0, mod = (int)(1e9 + 7), n = arr.size();
        long long total = 0;


        vector<int> nse = findNSE(arr);
        vector<int> psee = findPSEE(arr);

        for (int i = 0; i < n; i++) {
            int left = i - psee[i];
            int right = nse[i] - i;
            long long freq = left * right * 1LL;
            total += (freq * 1LL * arr[i]);
        }
        return total;
    }
    long long sumSubarrayMax(vector<int>& arr) {
        int ans = 0, mod = (int)(1e9 + 7), n = arr.size();
        long long total = 0;


        vector<int> nge = findNGE(arr);
        vector<int> pgee = findPGEE(arr);

        for (int i = 0; i < n; i++) {
            int left = i - pgee[i];
            int right = nge[i] - i;
            long long freq = left * right * 1LL;
            total += (freq * 1LL * arr[i]);
        }
        return total;
    }


    long long subArrayRanges(vector<int>& nums) {
        // brute force: O(n2);
        // optimal: using sum of subarray maximum and sum of subarray minimum,
        // its easier. next smaller element
        long long subMax = sumSubarrayMax(nums);
        long long subMin = sumSubarrayMins(nums);
        return subMax - subMin;
    }
};
```
