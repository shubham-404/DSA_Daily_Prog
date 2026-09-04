## The problem states that `nums1` has `m` elements, `nums2` has `n` elements, and `nums1` has enough space to occupy `m+n` elements. Can you merge the two arrays without using extra space?

- initial appraoch is to use another array to merge the two arrays and copy it to `nums1`, but that takes extra space.
- since the `nums1` already has extra space at the end, we can start from back, and add the largest elements from back. Its easy actually.

```cpp
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1;
        int j=n-1;
        int k=m+n-1;
        while (i>=0 && j>=0){
            if(nums1[i]>nums2[j]){
                nums1[k] = nums1[i];
                i--;
            } else{
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
        while(j>=0){
            nums1[k] = nums2[j];
            k--;
            j--;
        }
        while(i>=0){
            nums1[k] = nums1[i];
            k--;
            i--;
        }
    }

```