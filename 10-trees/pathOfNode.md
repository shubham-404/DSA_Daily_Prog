```Python
def getPath(root, a, path):
  if not root: return False
  
  path.append(root.val)
  
  if root.val == a.val: 
  	return True

  if getPath(root.left, a, path) or getPath(root.right, a, path):
    return True

  path.pop()
  return False
```
