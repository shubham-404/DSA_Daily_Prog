# Introduction to trees in DSA

Heirarchical data structure uses nodes and children to represent data.

- c++: using structures/classes.
- java: using classes.
- pythong: using classes.
- Binary Tree: each node can have atmax 2 children.
- Full BT: Every node must have either 2 or 0 children.
- Complete BT: All levels are completely filled. In case of single child, it must be as left as possible in same level.
- Perfect BT: All leaf nodes must be at same level.
- Balanced BT: Height of the BT can be atmax `log(N)`,`N-> number of nodes`
- Degenerate BT: Every node has a single child. Its like a singly LL.

# Trees in c++

```cpp
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val){
        data=val;
        left=null;
        right=null;
    }
}

int main(){
    struct Node* root = new Node(5);
    root->left = new Node(4);
    root->right = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(1);
}
```

# Trees in java

```java
class Node{
    int data;
    Node left;
    Node right;
    public Node(int val){
        this.data = val;
    }
}

public static void main(String[] args){
    Node root = new Node(5);
    root.left = new Node(4);
    root.right = new Node(3);
    root.left.left = new Node(2);
    root.left.right = new Node(1);
}
```

# Trees in python

```py
class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

root = Node(10)
root.left = Node(5)
root.right = Node(13)
```

# Tree traversals

## DFS - Depth first search

### 1. Inorder: [left - root - right]

```cpp
void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    print(root->data);
    inorder(root->right);
}
```

### 2. Preorder: [root - left - right]

```cpp
// recursive
void inorder(Node* root){
    if(!root) return;
    print(root->data);
    inorder(root->left);
    inorder(root->right);
}
```

```cpp
// iterative
```

### 3. Postorder: [left - right - root]

```cpp
void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    inorder(root->right);
    print(root->data);
}
```

## BFS - Breadth first search

### Level-wise traversal

```py
def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
    if not root: return []
    ans = [] # list of list
    queue = [] # stores level wise list
    queue.append(root)
    while len(queue):
        level = [] # left, right of each node
        for i in range(len(queue)):
            Node = queue[0]
            queue.pop(0)
            if Node.left:
                queue.append(Node.left)
            if Node.right:
                queue.append(Node.right)
            level.append(Node.val)
            # print(queue)
        ans.append(level)
    return ans
```

# Iterative inorder traversal

```py
```
