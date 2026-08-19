# Problem
Find and return the minimum element in a rotated sorted array with unique elements.

# Solution
Honestly, i don't know what i did, but whatever it is, its written below.
```cpp
int findMin(vector<int>& nums) {
    int n=nums.size(), left=0, right=n-1, minI=nums[0];
    while(left<=right){
        int mid=right-(right-left)/2;
        if(nums[left]<=nums[mid]){
            minI=min(minI, nums[left]);
            left=mid+1;
        } else{
            minI=min(minI, nums[right]);
            minI=min(minI, nums[mid]);
            right=mid-1;
        } 
    }
    return minI;
}
```