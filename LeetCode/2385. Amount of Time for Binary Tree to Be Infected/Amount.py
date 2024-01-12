from collections import deque

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def traversal (self,root, mp, target, startNode):
      if not root: 
        return None
      
      if(root.val == target):
        startNode[0] = root
        return root
      
      left = self.traversal(root.left,mp,target,startNode)
      if left:
        mp[left.val] = root
        return root
      
      right = self.traversal(root.right,mp,target,startNode)
      if right:
        mp[right.val] = root
        return root
      
      return None
      
  
    def amountOfTime(self, root: Optional[TreeNode], start: int) -> int:
      res = -1
      mp = {}
      startNode = [None]
      self.traversal(root,mp,start,startNode)
      q = deque(startNode[0])
      
      while q:
        size = len(q)
        res += 1 
        while size > 0:
          cur = q.popleft()
          size -= 1
          
          if cur.val in mp:
            q.append(mp[cur.val])    
          if cur.left and cur.left.val not in mp:
            q.append(cur.left)
          if cur.right and cur.right.val not in mp:
            q.append(cur.right)
            
      return res
          
          
           