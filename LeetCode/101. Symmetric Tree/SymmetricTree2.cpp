


 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root->left && !root->right){
          return true;
        }
        return isSymmetricPair(root->left,root->right);
    }

    bool isSymmetricPair(TreeNode* left,TreeNode* right){
      if(!left && !right){
        return true;
      }else if(!left || !right){
        return false;
      }
      if(left->val!=right->val){
        return false;
      }
      bool outerRes = isSymmetricPair(left->left,right->right);
      bool innerRes = isSymmetricPair(left->right,right->left);
      return outerRes && innerRes;
    }
};