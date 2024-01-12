#include <algorithm>


  //Definition for a binary tree node.
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

    // int count(TreeNode* root) {
    //   if(!root) return -1;
    //   int left = count(root->left)+1;
    //   int right = count(root->right)+1;
    //   return std::max(left,right);
    // }

     int count(TreeNode* root) {
      if(!root) return -1;
      return std::max(count(root->left)+1,count(root->right)+1);
    }

    void postOrder(TreeNode* root,  int& res){
      if(!root) return;
      postOrder(root->left,res);
      postOrder(root->right,res);
      int left = count(root->left)+1;
      int right = count(root->right)+1;
      res = std::max(res,left+right);
      return ;
    }

    int diameterOfBinaryTree(TreeNode* root) {
      int res = 0;
      postOrder(root,res);
      return res;
    }
    

    // int inorder(TreeNode* root, int diameter){
    //   if(!root) return diameter;
    //   int left = inorder(root->left,diameter)+1;
    //   int right = inorder(root->right,diameter+1);
    //   return std::max(left,right);
    // }


    // int diameterOfBinaryTree(TreeNode* root) {
    //   return inorder(root,0);
    // }
};