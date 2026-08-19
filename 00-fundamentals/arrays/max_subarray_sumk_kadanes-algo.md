# [-2,1,-3,4,-1,2,1,-5,4]

## Find the maxSum that can be obtained from all the subarrays of the given array.
OR
## Given an integer array nums, find the subarray with the largest sum, and return its sum.

### Approach 1:
Brute force: Two for loops to calculate currentSum and update maxSum --> O(n2)

### Approach 2:
`Kadane's Algorithm`: *If the sum of a subarray is negative, including that subarray cannot give a maxSum, so simply exclude it.*
Use one for loop, calculate the sum of subarrays, (do not calculate the sum of subarrrays already calculated!), if at any point the sum become less than zero, reset the sum, and start from ahead of that subarray.
