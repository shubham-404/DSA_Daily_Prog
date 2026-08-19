# Detect if a given LL has a cycle or not.

# Solution

## 1. Using Hashing

Use a *hashmap*(use `visited[temp] = 1;` to insert) or *unordered_set* (use `visited.insert(temp);` to insert) and `visited.find(temp) != visited.end(); ==> (since not equal to end, implies element already exists!)` to check if the node already exists in the map.

```cpp
bool hasCycle(ListNode* head) {
    // using hash
    unordered_set<ListNode*> mpp;
    ListNode* temp = head;
    while (temp != NULL) {
        if (mpp.find(temp) != mpp.end()) {
            return true;
        } else {
            mpp.insert(temp);
            temp = temp->next;
        }
    }
    return false;
}
```

## 2. Using Slow-Fast Pointer

Use a slow and fast pointer to detect the cycle.

Increment the `slow` by 1 and `fast` by 2.

This makes sure that in a cycle, the difference between the two reduces by 1, resulting in both pointers ending at same location if there is a cycle.

```cpp
// using tortoise-hare approach
bool hasCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(fast == slow) return true;
    }
    return false;
}
```
