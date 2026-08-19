# Problem: Reverse Words in a String

Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

 

Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.

# Solution
Simple logic and implementation.

- skip spaces to get to one end of each word.
- now skip characters to get to other end of that word.
- now extract the word using `str.substr(start, length)` function.
- add the word to result string and add a space.
- continue with next iteration after end of the word from original string.


```cpp
class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string result = "";
        int i = n - 1;

        while (i >= 0) {
            // Skip spaces
            while (i >= 0 && s[i] == ' ') i--;
            if (i < 0) break;

            int end = i;
            // Move to start of the word
            while (i >= 0 && s[i] != ' ') i--;
            int start = i + 1;

            // Extract word
            string word = s.substr(start, end - start + 1);

            if (!result.empty()) result += ' ';
            result += word;
        }

        return result;
    }
};
```