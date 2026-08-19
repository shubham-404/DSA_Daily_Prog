# Sum of Subarray Minimums

Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.

Example 1:

Input: arr = [3,1,2,4]
Output: 17
Explanation:
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4].
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.

Example 2:

Input: arr = [11,81,94,43,3]
Output: 444

# Solution

Brute force in O(N2).

```cpp
int sumSubarrayMins(vector<int>& arr) {
    int ans = 0, mod = (int)(1e9 + 7), n = arr.size();
    for (int i = 0; i < n; i++) {
        int minm = arr[i];
        for (int j = i; j < n; j++) {
            minm = min(minm, arr[j]);
            ans = (ans + minm) % mod;
        }
    }
    return ans;
}
//*Gives TLE*
```

Optimal using

## NOT ABLE TO UNDERSTAND THE SOLUTION. A LITTLE COMPLICATED BRO.
1. Store index in the nse and psee arrays.
2. initialize with 0, not -1.
3. calcuate contribution on the left subarrays and right subarrays.
4. handle int overflow using `int mod = (int) (1e9+7);` and `*1LL`.

```cpp
// next smaller element
vector<int> findNSE(vector<int> arr) {
    int n = arr.size();
    stack<int> stk;
    vector<int> nse(n);
    for (int i = n - 1; i >= 0; i--) {
        while (!stk.empty() && arr[stk.top()] >= arr[i]) {
            stk.pop();
        }
        nse[i] = !stk.empty() ? stk.top() : n;
        // empty stack means no next smaller element, to contribution is (n-i) as this element will be the smallest in all the next subarrays to its right.

        // push index to calculate count.
        stk.push(i);
    }
    return nse;
}

// previous smaller OR equal element
vector<int> findPSEE(vector<int> arr) {
    int n = arr.size();
    stack<int> stk;
    vector<int> psee(n);
    for (int i = 0; i<n; i++) {
        while (!stk.empty() && arr[stk.top()] > arr[i]) {
            stk.pop();
        }
        psee[i] = !stk.empty() ? stk.top() : -1;
        // empty stack means no next smaller element, to contribution is (n-i) as this element will be the smallest in all the next subarrays to its right.

        // push index to calculate count.
        stk.push(i);
    }
    return psee;
}
int sumSubarrayMins(vector<int>& arr) {
    int ans = 0, mod = (int)(1e9 + 7), n = arr.size();
    long long total=0;
    // approach: try to find the individual contribution of each element in
    // the answer. achieved by using nge and nsee concept

    vector<int> nse = findNSE(arr);
    vector<int> psee = findPSEE(arr);

    for (int i = 0; i < n; i++) {
        int left = i-psee[i];
        int right = nse[i] - i;
        long long freq = left*right*1LL;
        total = (total + ((freq*arr[i]*1LL) % mod)) % mod;
    }
    return (int)total;
}

```
