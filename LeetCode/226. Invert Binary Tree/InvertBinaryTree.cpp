#include <iostream>

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
    TreeNode* invertTree(TreeNode* root) {
      if(!root) return nullptr;
      root->left = invertTree(root->right);
      root->right = invertTree(root->left);
      return root;
    }

    void test(TreeNode* root){
      test(root->left);
      std::cout<<root->val<<std::endl;;
      test(root->right);
    }
};

main(){

  Solution s;
  TreeNode* root = new TreeNode(4);
  root->left = new TreeNode(2);
  root->right = new TreeNode(7);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(3);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(9);
  TreeNode* result = s.invertTree(root);
  s.test(result);

  return 0;
}