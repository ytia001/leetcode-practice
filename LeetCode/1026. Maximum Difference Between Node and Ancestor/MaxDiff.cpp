# include <algorithm>

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
    // int res = INT_MIN;
    // int dfs(TreeNode* root) {
    //   if(!root) return 0;

    //   int left = dfs(root->left);
    //   int right = dfs(root->right);

    //   int smaller = min(left,right);
    //   res = max(res,abs(root->val-smaller));

    //   return min(root->val,smaller);
    // }

    // int maxAncestorDiff(TreeNode* root) {
    //   dfs(root);
    //   return res;
    // }
    int res = INT_MIN;
    void dfs(TreeNode* root, int maxVal, int minVal){
      if(!root) return;
      res = max(abs(maxVal-root->val),abs(root->val-minVal));
      int newMaxVal = max(maxVal,root->val), newMinVal = min(minVal,root->val);
      dfs(root->left,newMaxVal,newMinVal);
      dfs(root->right,newMaxVal,newMinVal);
    }

    int maxAncestorDiff(TreeNode* root) {
      if(!root) return 0;
      dfs(root,root->val,root->val);
      return res;
    }
};