- # in cpp, when passing 2d array to a function,
- ## compulsary to pass number of columns, rows maybe skipped.

```cpp
// example
#include <bits/stdc++.h>
int maxRowSum(int mat[][3], int rows, int cols){
    int maxSum=INT_MIN;
    for(int i =0; i <rows; i++){
        int sum = 0;
        for(int j =0; j <cols; j++){
            sum += mat[i][j];
        }
        if(sum>maxSum){
            maxSum = sum;
        }
    }
    return maxSum;
}
```

