# Diameter of Binary Tree
 
Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

```py

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def calcDia(self, root, maxi):
        if not root:
            return 0
        lh = self.calcDia(root.left, maxi)
        rh = self.calcDia(root.right, maxi)
        maxi[0] = max(maxi[0], lh + rh)
        return 1 + max(lh, rh)

    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        maxi = [0]
        self.calcDia(root, maxi)
        return maxi[0]



```
