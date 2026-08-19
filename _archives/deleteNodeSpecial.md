# Problem
Give a node of a LL and you have to delete that from a given LL, but you are not provided with the head of the LL.

# Solution
Instead of directly removing the given node, we are changing its value to its next node and cutting the link of next node and connecting it to the node next to next node of the given node.


*Simple terms*: copy next node to given node, and delete the next node!
```cpp
void deleteNode(ListNode* node){
    if(!node) return; 
    node->data = node->next->data;
    node->next = node->next->next;
}
```
[4]->[5]*->[1]->[9]

[4]->[1]->[9]