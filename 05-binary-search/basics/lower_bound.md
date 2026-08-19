# Implement Lower Bound

Given a sorted array arr[] and a number target, the task is to find the lower bound of the target in this given array. The lower bound of a number is defined as the smallest index in the sorted array where the element is greater than or equal to the given number.

Note: If all the elements in the given array are smaller than the target, the lower bound will be the length of the array.

Examples :

- Input: arr[] = [2, 3, 7, 10, 11, 11, 25], target = 9
Output: 3

Explanation: 3 is the smallest index in arr[] where element (arr[3] = 10) is greater than or equal to 9.

- Input: arr[] = [2, 3, 7, 10, 11, 11, 25], target = 11
Output: 4

Explanation: 4 is the smallest index in arr[] where element (arr[4] = 11) is greater than or equal to 11.

- Input: arr[] = [2, 3, 7, 10, 11, 11, 25], target = 100
Output: 7

Explanation: As no element in arr[] is greater than 100, return the length of array.

# Solution

Same as BS, but instead of looking for the target, we find greater than or equal to (arr[i] >= target), then, to find the minimum index, make 'right' as 'mid-1'.
- Store the answer in separate variable, and update it with minimum value everytime an element is matched.

```cpp
int lowerBound(vector<int>& arr, int target) {
        // code here
        int n = arr.size(), lesser=0, greater=n-1, ans=INT_MAX;
        if(target>arr[n-1]) return n;
        while(lesser<=greater) {
            int mid = greater-(greater-lesser)/2;
            if(arr[mid] >= target) {
                ans = min(ans, mid);
                greater=mid-1;
            } else {
                lesser=mid+1;
            }
        }
        return ans;
    }
```
