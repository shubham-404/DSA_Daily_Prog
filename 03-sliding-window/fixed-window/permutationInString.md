# Permutation in String

Medium

Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
 
 # Solution

 This is my approach.
- use two maps, one for `s1`, another for `s2`.
- strictly set the window size to size of `s1`, and traverse in `s2`, maintaining and updating the map of `s2`, and comparing the two maps in each iteration. Return `true` if the maps match.

```py
def checkInclusion(self, s1: str, s2: str) -> bool:
    if len(s1) > len(s2): return False
    left, right = 0, len(s1)-1
    count1 = {}
    count2 = {}
    for i in s1:
        count1[i] = count1.get(i, 0) + 1

    # initial s2 map
    for i in range(len(s1)): # fixing window size in s2
        count2[s2[i]] = count2.get(s2[i], 0) + 1


    # now start sliding window
    while right < len(s2):
        if count1 == count2: return True 
        count2[s2[left]] = count2.get(s2[left], 0) - 1
        if count2[s2[left]] == 0:
            del count2[s2[left]]
        left += 1
        right += 1
        if right < len(s2):
            count2[s2[right]] = count2.get(s2[right], 0) + 1
    if count1 == count2: return True
    return False

```
