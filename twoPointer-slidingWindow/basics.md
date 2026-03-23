# Sliding window tips and tricks.

- use while to shrink the window


*`sliding window template`*
```cpp
int left=0;
for(int right=0; right<n; right++){
    // 1. expand window
    // include nums[right]

    // 2. fix the window
    while(window is invalid){
        // remove nums[left]
        left++;
    }

    // 3. update answer
    ans = max(ans, right-left+1);
}


```
