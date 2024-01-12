#include <queue>
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
    void postOrder(TreeNode* root,int depth, int& res){
      if(!root) return;
      postOrder(root->left,depth + 1,res );
      postOrder(root->right,depth + 1,res );
      res = std::max(res,depth);
      return;
    }

    int maxDepth(TreeNode* root) {
      if(!root) return 0;
      int res = 0;
      postOrder(root,1,res);
      return res;
    }

    int maxDepth(TreeNode* root) {
      if(!root) return 0;
      std::queue<TreeNode*> q;
      q.push(root);
      int res = 0;
      while(!q.empty()){
        int size = q.size();
        res ++;
        while(size-->0){
          TreeNode* node = q.front();
          q.pop();
          if(node->left) q.push(node->left);
          if(node->right) q.push(node->right);
        }
      }
      return res;
    }
};