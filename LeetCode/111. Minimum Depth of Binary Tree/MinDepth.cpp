#include <algorithm>
#include <queue>

using namespace std;

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

    int minDepth(TreeNode* root) {
      if(!root) return 0;

      int depth = 0;
      queue<TreeNode*> q;
      q.push(root);
      while(!q.empty()){
        depth++;
        int size = q.size();
        for(int i = 0 ; i < size ; i++){
          TreeNode* node = q.front();
          q.pop();
          // cout<<node->val<<endl;
          if(!node->left && !node->right){
            return depth;
          }else{
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
          }
        }
      }
      return depth;
    }

    int minDepth(TreeNode* root) {
      if(!root) return 0;
      if(!root->left && !root->right) return 1;

      int left = minDepth(root->left);
      int right = minDepth(root->right);

      if(left && right){
        return min(left,right) + 1;
      }else if(!left){
        return right + 1;
      }else{
        return left + 1;
      }
    }
};