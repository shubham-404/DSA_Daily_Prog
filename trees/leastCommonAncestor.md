# Least Common Ancestor

Q. You have to find the lowest common ancestor of two given nodes.

## Brute force

- Find the path of each given node.
- Match both paths from starting, and return the last common node in the paths.
- TC: O(2N) + O(N) = O(3N)
- SC: O(2N)

## Optimal

* Traverse the whole tree using DFS.
* return `False` if left/right is NULL OR return `NODE` if the node is one of the given nodes.
* compare the return values of the left recursion and the right recursion.
* if one of them is NOT False, it is one of the given nodes, so return that node from now on.
* keep returning the NOT-False value, until you find a node where both left and righ recursion returns NOT-False values. This is our answer.
* From here on, return only the answer node.
* finally the answer node is returned.

- TC: O(N)
- SC: O(N) -> height of the tree (worst->N, avg->logN)

 
