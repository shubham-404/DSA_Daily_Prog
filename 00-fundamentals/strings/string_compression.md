# Problem
## String Compression

Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters in chars:

If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.

After you are done modifying the input array, return the new length of the array.

You must write an algorithm that uses only constant extra space.

Note: The characters in the array beyond the returned length do not matter and should be ignored.

 

Example 1:

Input: chars = ["a","a","b","b","c","c","c"]
Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".
Example 2:

Input: chars = ["a"]
Output: Return 1, and the first character of the input array should be: ["a"]
Explanation: The only group is "a", which remains uncompressed since it's a single character.
Example 3:

Input: chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
Output: Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].
Explanation: The groups are "a" and "bbbbbbbbbbbb". This compresses to "ab12".


# Solution
- ## The main challenge here is to solve the problem in-place.

We will traverse through each character and untill it changes, we keep increasing its count.

When the character changes, we update the character and its count in the string.

In the end, we trim the string using str.substr(start, length). 

However that wouldn't be necessary as we only need to return the size of the new string. so we can return the index we are writing at, at the end of the loop.

```cpp
class Solution {
public:
    int compress(vector<char>& chars) {
        // ["a","a","b","b","c","c","c"]
        int n = chars.size();
        int idx = 0;
        if(n<=1) return n;
        for(int i=0; i<n; i++){
            char currCh = chars[i];
            int count =0;
            while(i<n && currCh == chars[i]){
                i++, count++;
            }
            if(count == 1) chars[idx++] = currCh;
            else{
                chars[idx++] = currCh;
                string cnt = to_string(count);
                for(auto j: cnt){
                    chars[idx++] = j;
                }
            }
            i--;
        } 
        return idx;
    }
};
```