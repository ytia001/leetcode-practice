#include<iostream>

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
    bool isCompleteTree(TreeNode* root);
    bool checkCompleteBT(TreeNode* root,int& depth,bool& result);
    bool isCompleteChild(TreeNode* root);
    bool isCompleteTreeProto(TreeNode* root);
    bool checkAll(TreeNode* root, bool canLeftOnly);
    bool isCompleteTreeProto2(TreeNode* root);
    bool isCompleteAllExceptLast(TreeNode* rootLeft, TreeNode* rootRight);
};