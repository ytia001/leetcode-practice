#include <algorithm>
#include <vector>

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

    void inorder(TreeNode* root, vector<int>& asc){
      if(!root) return;
      inorder(root->left,asc);
      asc.push_back(root->val);
      inorder(root->right,asc);
    }

    bool isValidBST(TreeNode* root) {
      vector<int> asc;
      inorder(root,asc);
      for(int i = 1; i <asc.size() ;i++){
        if(asc[i-1]>=asc[i]) return false;
      }
      return true;
    }

// PROTO 1 

    // int smallest(TreeNode* root){
    //   if(!root) return INT_MAX;
    //   int left = smallest(root->left);
    //   int right = smallest(root->right);
    //   return min({root->val,left,right});
    // }

    // int largest(TreeNode* root){
    //   if(!root) return INT_MIN;
    //   int left = largest(root->left);
    //   int right = largest(root->right);
    //   return max({root->val,left,right});
    // }


    // bool isValidBST(TreeNode* root) {
    //   if(!root) return true;
    //   if(!root->left && !root->right) return true;
    //   bool res = true;
    //   int leftVal = largest(root->left);
    //   int rightVal = smallest(root->right);
    //   if(rightVal<= root->val || leftVal>= root->val){ 
    //     res = false;
    //   }
    //   return res && isValidBST(root->left) && isValidBST(root->right);
    // }

// PROTO 2

    //bool res = true;

    // int check(TreeNode* root){
    //   if(!root) return 0;
    //   int left = check(root->left);
    //   int right = check(root->right);
    //   if( (right != 0 && right<= root->val) || (left != 0 && left>= root->val)){
    //     res = false;
    //   }
    //   return max(root->val,max(left,right));
    // }


    // bool res = true;
    
    // TreeNode* check(TreeNode* root,TreeNode* prev){
    //   if(!root) return prev;
    //   TreeNode* previous = check(root->left,prev);
    //   if(previous){
    //     if(root->val <= previous->val) res = false;
    //   }
    //   //prev = root;
    //   check(root->right,root);
    //   return root;
    //   //return check(root->right,root);
    // }

    // bool check(TreeNode* root){
    //   bool leftCheck = (!root->left) ? true : (root->val > root->left->val) ? true : false;
    //   bool rightCheck = (!root->right) ? true : (root->val <  root->right->val) ? true : false;

    //   bool rootCheck = leftCheck && rightCheck;
    //   bool leftNode = (!root->left)? true: check(root->left);
    //   bool rightNode = (!root->right)? true: check(root->right);
  
    //   //return (leftCheck && rightCheck) && check(root->left) && check(root->right);
    //   return rootCheck && leftNode && rightNode;
    // }

    // bool isValidBST(TreeNode* root) {
    //   if(!root) return true;
    //   check(root,nullptr);
    //   return res;
    // }
};