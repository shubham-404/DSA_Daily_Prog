# Problem

# Solution

```cpp
bool isValid(string s) {
    /* // // MY APPROACH
        // stack<char> st;
        // for(char ch: s){
        //     if(ch == '(' || ch == '{' || ch == '['){
        //         st.push(ch);
        //     }
        //     else if(st.empty()) return false;
        //     else if(ch == ')' && st.top() == '(') st.pop();
        //     else if(ch == '}' && st.top() == '{') st.pop();
        //     else if(ch == ']' && st.top() == '[') st.pop();
        //     else return false;
        // }
        // return st.empty();

    */

        // using map for interview friendly approach.
        stack<char> st;
        unordered_map<char, char> mp = {
            {')' , '('},
            {'}' , '{'},
            {']' , '['}
        };
        for(char ch:s){
            if(mp.count(ch)){
                if(st.empty() || st.top()!=mp[ch]){
                    return false;
                }
                st.pop();
            } else st.push(ch);
        }
        return st.empty();
    }
```
