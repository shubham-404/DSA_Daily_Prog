# Add Two Numbers
 
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.


Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]


Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]


# Solution
The problem is as simple as it looks, it just tests how well do you understand the working of linked lists.
Use a carry variable to calculate the single digit sum at each step and keep updating the carry.

*Use newNode to save the data and add it to the result.
*Use a dummy node for starting off with the calculation and return the `ansHead->next` ans first head was a dummy.

You're good to go!

```cpp
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ansHead = new ListNode();
        ListNode* ans = ansHead;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int carry = 0;
        while (temp1 && temp2) {
            int add = temp1->val + temp2->val + carry;
            carry = add / 10;
            ListNode* newNode = new ListNode(add % 10);
            ans->next = newNode;
            ans = ans->next;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        if (!temp1) {
            while (temp2) {
                int add = temp2->val + carry;
                carry = add / 10;
                ListNode* newNode = new ListNode(add % 10);
                ans->next = newNode;
                ans = ans->next;
                temp2 = temp2->next;
            }
        }
        if (!temp2) {
            while (temp1) {
                int add = temp1->val + carry;
                carry = add / 10;
                ListNode* newNode = new ListNode(add % 10);
                ans->next = newNode;
                ans = ans->next;
                temp1 = temp1->next;
            }
        }
        if(carry){
                ListNode* newNode = new ListNode(carry);
                ans->next = newNode;
                ans = ans->next;
        }
        return ansHead->next;
    }

```