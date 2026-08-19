// Stack is based on LIFO (Last in first out) principle.
// Element pushed last is popped first!

#include<bits/stdc++.h>
// #include<stack>
// #include<queue>
using namespace std;

int main(){    
    // for stack
    stack<int> st;
    st.push(0);
    cout << st.top();
    st.pop();
    cout << st.top();
    st.size();
    st.empty();

    // for queue
    // Queue is based on FIFO(First in first out) principle, that is
    // the element pushed first is popped first.
    queue<int> que;
    que.push(0);
    cout << que.front();
    que.pop();
    cout << que.front();
    que.back();
    que.size();
    que.empty();

    return 0;
}