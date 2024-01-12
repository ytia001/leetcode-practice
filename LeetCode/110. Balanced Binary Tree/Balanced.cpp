#include <cmath>
#include <algorithm>


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

    int postOrder(TreeNode* root,bool& res){
      if(!root) return 0;
      int left = postOrder(root->left,res);
      int right = postOrder(root->right,res);
      if(abs(left-right)>1){
        res = false;
      }
      return std::max(left,right)+1;
    }

    bool isBalanced(TreeNode* root) {
      if(!root) return true;
      bool res = true;
      postOrder(root,res);
      return res;
    }
};