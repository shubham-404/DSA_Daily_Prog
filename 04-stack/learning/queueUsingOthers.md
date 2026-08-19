# Implement Queue using arrays
```cpp
class myQueue {
    vector<int> Que;
    int start, end, cap;

  public:
    myQueue(int n) {
        start = -1;
        end = -1;
        cap = n;
        Que.resize(n);
    }

    bool isEmpty() {
        return (start == -1);
    }

    bool isFull() {
        // return (end + 1 == start || end == cap - 1);
        return ((end+1)%cap == start );
    }

    void enqueue(int x) {
        if(isFull()) return;
        if(isEmpty()) {
            start=0, end=0;
        }else{
            end = (end+1) % cap;
        }
        Que[end] = x;
    }

    void dequeue() {
        if(isEmpty()) return;
        if(start == end){
            start = -1, end = -1;
        } else{
            start =( start + 1 )% cap;
        }
    }

    int getFront() {
        if(!isEmpty()) return Que[start];
        return -1;
    }

    int getRear() {
        if(!isEmpty()) return Que[end];
        return -1;
        
    }
};
```
---
# Implement Queue using Linked List
```cpp
class Node {
  public:
    int data;
    Node* next;

    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};

class myQueue {
    Node* que, *start, *end;
    int sz;

  public:
    myQueue() {
        // Initialize your data members
        que = new Node(-1);
        start = que, end = que;
        sz = 0;
    }

    bool isEmpty() {
        // check if the queue is empty
        return (start->next == nullptr);
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue
        Node* newNode = new Node(x);
        end->next = newNode;
        end = newNode;
        sz++;
    }

    void dequeue() {
        // Removes the front element of the queue
        if(isEmpty()) return;
        Node *temp = start ->next;
        start->next = temp->next;
        if(start->next == nullptr){ //stack empty with dummy element
            end = start;
        }
        delete temp;
        sz--;
        
    }

    int getFront() {
        // Returns the front element of the queue
        // If queue is empty, return -1
        if(isEmpty()) return -1;
        return start->next -> data;
    }

    int size() {
        // Returns the current size of the queue.
        return sz;
        
    }
};

```
---
# Implement Queue using Stack
```cpp

```
class MyQueue {
public:
    stack<int> st1, st2;
    int front;
    MyQueue() {}

    void push(int x) {
        if (st1.empty())
            front = x;
        st1.push(x);
    }

    int pop() {
        while (st1.size() > 1) {
            st2.push(st1.top());
            st1.pop();
        }
        int popped = st1.top();
        st1.pop();
         if(!st2.empty()) front = st2.top();
        while (!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
        return popped;
    }

    int peek() {
        
        if (!st1.empty())
            return front;
        return -1;
    }

    bool empty() { return st1.empty(); }
};

---