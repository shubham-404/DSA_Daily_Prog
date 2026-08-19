# Problem

Reverse a linked list

1. Iterative approach
2. Recursive approach

# Solution

### 1. Iterative

This one is simple. Just use three nodes to mark prev, temp and next node, swap the next pointers, and keep doing until head is NULL.

```cpp
ListNode* reverseList(ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;
    ListNode* prev = head;
    ListNode* temp = head->next;
    prev->next = NULL; // last node
    while(temp){
        ListNode* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}
```

### 2. Recursive

Since I am new to recursion, this one felt a bit tricky.

Basics: Recursion is breaking down a problem into smaller one, solving it and using its result to solve the bigger problem.

From the last node, return it with its `next` as `NULL`, and use it to swap the `next` pointer at each recursion level.

```cpp
ListNode* reverseList(ListNode* head) {
    if(head==NULL || head->next==NULL){
        return head;
    } 
    ListNode* newHead = reverseList(head->next);
    ListNode* front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}
```
