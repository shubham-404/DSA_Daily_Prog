# Problem

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
Given a string s, return true if it is a palindrome, or false otherwise.

# Solution

It's simple.
Use two pointers and check if the selected character is alphanumeric, skip and continue if yes, proceed if no.
Then, check if the characters at the two pointers are same or not, if no, return false, else, keep checking. return true outside of the while loop.

# code

```cpp
class Solution {
    public:
    bool isFreqSame(int freq1[], int freq2[]) {
        for (int i = 0; i < 26; i++) {
            if (freq1[i] != freq2[i])
                return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int freq1[26] = {0}; // since elements are limited we're using array
        for (char ch : s1) {
            freq1[ch - 'a']++;
        }
        int n1 = s1.length();
        int n2 = s2.length();

        for (int i = 0; i <= n2 - n1; i++) {
            int windFreq[26] = {0}; // window frequncy array
            for (int j = i; j < i + n1; j++) {
                windFreq[s2[j] - 'a']++;
            }
            if (isFreqSame(freq1, windFreq))
                return true;
        }
        return false;
    }

};
```
