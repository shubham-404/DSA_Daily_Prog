# Balanced Binary Tree

Given a binary tree, determine if it is height-balanced.

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: true

Example 2:

Input: root = [1,2,2,3,3,null,null,4,4]
Output: false

```py
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def height(self, root):
        if not root: return 0
        lh = self.height(root.left)
        rh = self.height(root.right)
        if(lh == -1 or rh == -1): return -1
        if abs(lh - rh) > 1 : return -1
        return 1+max(lh, rh)

    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        h = self.height(root)
        return h != -1
```
