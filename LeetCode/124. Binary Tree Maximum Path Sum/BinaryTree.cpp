#include <numeric>
#include <algorithm>

using namespace std;

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

    int res = INT_MIN;

    int maxSearch(TreeNode* root){
      if(!root) return 0;

      int leftMax = maxSearch(root->left);
      int rightMax = maxSearch(root->right);

      res = max(res, leftMax + rightMax + root->val);

      if( leftMax > 0 && leftMax >= rightMax){
        res = max(res,leftMax+root->val);
        return root->val + leftMax;
      }
      else if (rightMax > 0 && rightMax > leftMax){
        res = max(res,rightMax+root->val);
        return root->val + rightMax;
      }
      
      res = max(res,root->val);
      return root->val;
    }

    int maxPathSum(TreeNode* root) {
      maxSearch(root);
      return res; 
    }


    // int res = INT_MIN;

    // int maxSearch(TreeNode* root){
    //   if(!root) return 0;
    //   //if(!root->left && !root->right) return root->val;

    //   int leftMax = maxSearch(root->left);
    //   int rightMax = maxSearch(root->right);

    //   int sum = leftMax + rightMax;
    //   if(sum > 0 && sum > leftMax && sum > rightMax) {
    //     res = max(res,sum+root->val);
    //     return sum + root->val;
    //   }
    //   else if( leftMax > 0 && leftMax > rightMax){
    //     res = max(res,leftMax+root->val);
    //     return sum + leftMax;
    //   }
    //   else if (rightMax>0 && rightMax > leftMax){
    //     res = max(res,rightMax+root->val);
    //     return sum + rightMax;
    //   }
      
    //   res = max(res,root->val);
    //   return root->val;
    // }

    // int maxPathSum(TreeNode* root) {
    //   //if(!root) return 0;
    //   maxSearch(root);
    //   return res; 
    // }
};