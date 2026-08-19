# Implement stack using array

```cpp
class myStack {
  public:
    int top, cap;
    vector<int> stk;
    myStack(int n) { // constructor
        top = -1;
        cap = n;
        stk.resize(n);
    }

    bool isEmpty() {
        return top == -1;

    }

    bool isFull() {
        return top == cap-1;
    }

    void push(int x) {
        if(isFull()) return;
        stk[++top] = x;
    }

    void pop() {
        if (isEmpty()) return;
        top--;
    }

    int peek() {
        if(isEmpty()) return -1;
        return stk[top];
    }
};
```
---

# Implement stack using Linked List

```cpp
class myStack {
    Node* stk;
    int sz;

  public:
    myStack() {
        // Initialize your data members
        sz = 0;
        stk = new Node(-1);
    }

    bool isEmpty() {
        // check if the stack is empty
        return stk->next == nullptr;
    }

    void push(int x) {
        // Adds an element x at the top of the stack
        Node* newNode = new Node(x);
        Node* temp = stk;
        while(temp->next){
            temp = temp->next;
        }
        temp -> next = newNode;
        sz++;
    }

    void pop() {
        // Removes the top element of the stack
        if(!stk || !stk->next){
            stk->next= NULL;
            return;
        } else{

        Node* temp = stk->next;
        Node* prev = stk;
        while(temp->next){
            temp=temp->next;
            prev=prev->next;

        }
        prev->next = NULL;
        }
        sz--;
    }

    int peek() {
        // Returns the top element of the stack
        // If stack is empty, return -1
        if(!stk) return -1;
        Node* temp = stk;
        while(!isEmpty() && temp->next){
            temp = temp->next;
        }
        return temp->data;
    }

    int size() {
        return sz;
        // Returns the current size of the stack.
    }
};
```
---

# Implement stack using Queue
```cpp
class MyStack {
public:
    // using 2 queues.
    queue<int> q1, q2;
    MyStack() {
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        while(q1.size() > 1){
            q2.push(q1.front());
            q1.pop();
        }
        int ans = q1.back();
        q1.pop();
        swap(q1, q2);
        return ans;
    }
    
    int top() {
        return q1.back();
    }
    
    bool empty() {
        return q1.empty();
    }
};

```
---


