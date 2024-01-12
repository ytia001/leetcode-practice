#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;


// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      if(p==root || q==root) return root;
      if(p->val > root->val && q->val > root->val){
        TreeNode* node = lowestCommonAncestor(root->right,p,q);
        if(node) return node;
      }else if(p->val < root->val && q->val < root->val){
        TreeNode* node = lowestCommonAncestor(root->left,p,q);
        if(node) return node;
      }else{
        return root;
      }
      return root;
    }
};