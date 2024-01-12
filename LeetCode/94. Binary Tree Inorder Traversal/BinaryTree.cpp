# include <vector>
# include <stack>

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

    vector<int> inorderTraversal(TreeNode* root) {
      vector<int> res;
      stack<TreeNode*> st;
      while(!st.empty() || root){
        if(!root){
          if(st.empty()) break;
          root = st.top();
          res.push_back(root->val);
          st.pop();
          root = root->right;
        }else{
          st.push(root);
          root = root->left;
        }  
      }
      return res;
    }

    // vector<int> inorderTraversal(TreeNode* root) {
    //   vector<int> res;
    //   inorder(root,res);
    //   return res;
    // }

    // void inorder(TreeNode* root,vector<int>& vect){
    //   if(!root) return;
    //   inorder(root->left,vect);
    //   vect.push_back(root->val);
    //   inorder(root->right,vect);
    // }
};