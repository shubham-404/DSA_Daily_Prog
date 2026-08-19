# Rearrange Array Elements by Sign

You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.

You should return the array of nums such that the array follows the given conditions:

Every consecutive pair of integers have opposite signs.
For all integers with the same sign, the order in which they were present in nums is preserved.
The rearranged array begins with a positive integer.
Return the modified array after rearranging the elements to satisfy the aforementioned conditions.

# Solution 1

```cpp
// create another two arrays positive and negative, then alternatively add elements to result array.
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos, neg, result(n);
        for (int i : nums) {
            if (i >= 0)
                pos.push_back(i);
            else
                neg.push_back(i);
        }
        int i = 0, j = 0, k = 0;
        while (i < n) {
            result[i++] = pos[j++];
            result[i++] = neg[k++];
        }
        return result;
    }
```

# Solution 2
using two pointers in O(n) -> i couldn't really make it work. so now i am viewing the solution.
so we'll be using even and odd indices.

```cpp
// traverse the array and add positive nos at even positions and add negative nos at odd positions.
vector<int> rearrangeArray(vector<int>& nums) {
        int pos = 0, neg = 1, idx = 0, n = nums.size();
        vector<int> result(n);
            for (int x : nums) {
                if (x >= 0 && pos<=n) {
                    result[pos] = x;
                    pos += 2;
                } else {
                    result[neg] = x;
                    neg += 2;
                }
            }
        return result;
    }
```