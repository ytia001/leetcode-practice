
 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
     TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      if(!root) return nullptr;
      if(root == p || root == q) return root;
      TreeNode* left = lowestCommonAncestor(root->left,p,q);
      TreeNode* right = lowestCommonAncestor(root->right,p,q);
      if(left && !right){
        return left;
      } 
      else if(right && !left){
        return right;
      }else if(left && right){
        return root;
      }
      return nullptr;
    }


    // bool search(TreeNode* root, TreeNode* target){
    //   if(!root) return false;
    //   if(search(root->left,target)) return true;
    //   if(search(root->right,target)) return true;
    //   if(root==target) return true;
    //   return false;
    // }

    // TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //   if(root==p || root==q) return root;
    //   bool leftP = search(root->left,p);
    //   bool leftQ = search(root->left,q);
    //   if(leftP && leftQ){
    //     return lowestCommonAncestor(root->left,p,q);
    //   }else if(!leftP && !leftQ){
    //     return lowestCommonAncestor(root->right,p,q);
    //   }else{
    //     return root;
    //   }
    // }
};