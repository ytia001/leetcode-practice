#Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
      res = 0
      def search(root,maxVal,minVal):
        if not root: 
          return
        res = max(res,max(abs(maxVal-root.val),abs(root.val-minVal)))
        newMaxVal, newMinVal = max(root.val,maxVal) , min(root.val,minVal)
        search(root.left,newMaxVal,newMinVal)
        search(root.right,newMaxVal,newMinVal)
      search(root,root.val,root.val)
      return res
        