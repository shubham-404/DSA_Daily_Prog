# Problem

Design a stack that supports push, pop, top, and retrieving the minimum element in **constant time**.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
**You must implement a solution with O(1) time complexity for each function.**
# Solution
Important Note: use `<=` in `val <= mins.top()` to handle duplicate minimum values and avoid removing a minimum value that still exists in original stack.
```cpp
class MinStack {
public:
    stack<int> original;
    stack<int> mins;
    MinStack() {
    }

    void push(int val) {
        original.push(val);
        if(mins.empty() || val <= mins.top()) mins.push(val);
    }

    void pop() {
        if(original.empty()) return;
        if(original.top() == mins.top()) mins.pop();
        original.pop();
    }

    int top() {
        return original.empty() ? -1 : original.top();
    }

    int getMin() {
        return mins.empty() ? -1 : mins.top();
    }
};
```
