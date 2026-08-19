# Problem

We have to find the middle node of a given LL.
Brute Force uses two traversals, one to find the length, another to find the middle element.

Ease Peezy!

## Optimal

Using Slow-Fast Pointer OR Tortoise-Hare Method.
Use two pointers, 'slow' & 'fast' and move them simulatneously.

Increment 'slow' once and 'fast' twice. So as the 'fast' reaches the end (NULL or last node), the slow automatically reaches the middle node.

```cpp
ListNode* midNode(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
```
