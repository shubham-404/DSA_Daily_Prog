# Trapping Rain Water

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Example 1:

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9

# Solution

- The approach is the find the leftMax(prefixMax) and the rightNax(suffixMax) for each element.
- You can do that with a `TC = O(2N)`, `SC = O(N)` simply using two pointers.
- Or in `TC = O(N)`, `SC = O(1)` using the optimized approach, i.e. using two pointers, we calculate leftMax and rightMax while traversing.

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftMax = 0, rightMax = 0, water = 0;
        int leftPt = 0, rightPt = n - 1;
        while (leftPt < rightPt) {
            if (height[leftPt] < height[rightPt]) {
                if (height[leftPt] >= leftMax) {
                    leftMax = height[leftPt];
                } else{
                    water += leftMax - height[leftPt];
                }
                leftPt++;
            } else { // height[leftPt] >= height[rightPt]
                if (height[rightPt] >= rightMax) {
                    rightMax = height[rightPt];
                } else{
                    water += rightMax - height[rightPt];
                }
                rightPt--;
            }
        }
        return water;
    }
};
```
