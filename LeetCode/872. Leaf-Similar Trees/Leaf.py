# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def leafSimilar(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
      
      def inorder(self,lst: List[int],root: [TreeNode]):
        if(root is None): return
        
        inorder(lst,root.left)
        if(root.left is None and root.right is None):
          list.append(root.value)
        inorder(lst,root.right)
      
      rootList1 = [] , rootList2 = []
      inorder(rootList1,root1)
      inorder(rootList2,root2)
      
      return rootList1 == rootList2
        
        