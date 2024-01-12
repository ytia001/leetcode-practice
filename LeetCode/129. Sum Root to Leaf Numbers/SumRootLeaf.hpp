#include <vector>
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
    int sumNumbers(TreeNode* root);
    void sumPreOrder(std::vector<int>& sumRootTree, TreeNode* root, int currSum = 0);
};