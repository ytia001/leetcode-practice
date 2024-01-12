#include <vector>
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
    int curDepth = -1;

    void rightSearch(TreeNode* root, vector<int>& res,int depth){
      if(!root) return;
      if(depth > curDepth){
        res.push_back(root->val);
        curDepth = max(curDepth,depth);
      }
      rightSearch(root->right,res,depth+1);
      rightSearch(root->left,res,depth+1);
    }

    vector<int> rightSideView(TreeNode* root) {
      vector<int> res;
      rightSearch(root,res,0);
      return res;
    }
};