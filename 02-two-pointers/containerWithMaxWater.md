## Container With Most Water

### You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

### Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.
--------------

## Solution & approach
### Brute Force 
It includes finding all the areas by running two loops, and updating maxWater in each iteration.

### Optimal
Use of `Two Pointer Apporach` will do the job in O(n).
Keep one pointer at initial, and another at the end, calculate width (left-right), and minHeight, to obtain area. Check with maxWater, and move the pointer which is smaller, in order to keep the max area.
