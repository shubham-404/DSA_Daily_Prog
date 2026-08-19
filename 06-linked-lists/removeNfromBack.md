# Remove Nth Node From End of List

Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]


Example 2:

Input: head = [1], n = 1
Output: []


Example 3:

Input: head = [1,2], n = 1
Output: [1]
 
# Solution
### Brute force: 
Traverse to the end, count the length, traverse again to delete the `(count-n)th` element. - SC: `O(N)`

### Optimal approach: 
Use two pointers.
One pointer `fast` to move `n` places ahead, and pointer `slow` to start late.
as the `fast` reaches the end, `slow` will automatically be before the target node, and delete that node.
```cpp
ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (!head || n == 0) return head;

    ListNode* fast = head;
    ListNode* slow = head;

    while (n > 0 && fast) {
        fast = fast->next;
        n--;
    }

    if (!fast) return head->next;

    while (fast->next) {
        slow = slow->next;
        fast = fast->next;
    }

    ListNode* delNode = slow->next;
    slow->next = delNode->next;
    delete delNode;   // 🔥 fix

    return head;
}


```
