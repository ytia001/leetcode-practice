# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution(object):
    res = 0
    
    def rangeSumBST(self, root, low, high):
      
      if(not root): 
        return 0
      
      left = self.rangeSumBST(root.left,low,high) 
      right = self.rangeSumBST(root.right,low,high) 
      
      return left + right + (root.val if low <= root.val <= high else 0) 
    
      
      
      
        