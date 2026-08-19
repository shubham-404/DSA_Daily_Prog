# Remove K Digits

Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.

Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.

# Solution

The aim is to return the smallest possible number.
Approach:

- the biggest place (left-most) digit has to be smaller.
- Start traversing from the left.
- keep storing in a stack untill a bigger digit is found and k>0.
- pop from stack if `digit>st.top()` && `k>0`.
- edge cases:
  - k=0 : return nums
  - k=N : return "0";
  - ans="000" : return "0";
  - ans="0034" : return "34";
  - k>0 and the string ran out -> remove last k digits from right.
  -

```cpp
string removeKdigits(string num, int k) {
    if (k == 0)
        return num;
    int n = num.length(), k2 = k;
    if (k == n)
        return "0";

    stack<char> st;
    for (int i = 0; i < n; i++) {
        while(!st.empty() && k2>0 && st.top()>num[i]){
            st.pop();
            k2--;
        }
        st.push(num[i]);
    }
    while(k2>0){
        st.pop();
        k2--;
    }

    string ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }

    while(ans.length()>0 && ans[ans.length()-1]=='0'){
        ans.pop_back();
    }

    if(ans.length()==0) return "0";
    reverse(ans.begin(), ans.end());
    return ans;
}

```
