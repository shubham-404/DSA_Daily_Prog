## Book Allocation Problem

Q. There are N books, each ith book has A[i] number of pages.

- You have to allocate books to M number of students so that the maximum number of pages allocated to a student is minimum.
  - Each book should be allocated to a student.
  - Each student has to be allocated at least one book.
  - Allotment should be in contiguous order.
- Calculate and return that minimum possible number.
- Return -1 if a valid assignment is not possible.

## Example:

arr = [2, 1, 3, 4], N=4, M=2
total = 10

- possible answers:
  - a) s1=2, s2=8  #max-pages=8
  - b) s1=3, s2=7  #max-pages=7
  - c) s1=6, s2=4  #max-pages=6 - minimum - answer

If M>N, return -1

# Solution:

apply BS on the range 0-sum(arr) as the answer definitely lies in-between.

if mid -> invalid => answer lies in right half
if mid -> valid => answer can be current value, or may lie in left half(smaller)
also design a function to check valid and invalid (check contigious allocation)

## code

```cpp
bool isValid(vector<int> &arr, int n, int m, int maxAllowedPages){
    students=1, pages=0;

    for(int i=0; i<n; i++){
        if(arr[i] > maxAllowedPages) return -1;

        if(pages + arr[i] <= maxAllowedPages){
            pages += arr[i];
        } else{
            students++; 
            pages = arr[i];
        }
    }
    return students > a ? false : true;
}

int allocateBooks(vector<int> &arr, int n, int m){
    if(m>n) return -1; // edge case

    int sum = 0;
    for(int i : arr){ // find sum
        sum += i;
    }

    int ans = -1;
    int st=0, end=sum;

    while(st <= end){ // BS
        int mid = st + (end-st)/2;
        if(isValid(arr, n, m, mid)){ // left
            ans = mid;
            end = mid - 1;
        } else{ // right
            st = mid + 1;
        }
    }
    return ans;
}
```
