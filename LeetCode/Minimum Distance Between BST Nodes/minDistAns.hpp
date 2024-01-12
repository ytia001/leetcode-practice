#include <limits.h>
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

            // input: TreeNode* root = new root (4)
            // root -> left = new TreeNode(0);
            // root -> right = new TreeNode(48);
            // root -> left -> left = new TreeNode(null);
            // root -> left -> right = new TreeNode(null);
            // root -> right -> left = new TreeNode(12);
            // root -> right -> right = new TreeNode(49);
class Solution {
    public:
        int minDiffInBST(TreeNode* root) {
        TreeNode* prev = nullptr;
        int minDiff = INT_MAX;
        inorderTraversal(root, prev, minDiff);
        return minDiff;
    }

    void inorderTraversal(TreeNode* root, TreeNode*& prev, int& minDiff) {
        if (!root) return;
        inorderTraversal(root->left, prev, minDiff);
        if (prev) minDiff = std::min(minDiff, root->val - prev->val);
        prev = root;
        inorderTraversal(root->right, prev, minDiff);
    }
};

