#include <vector>
#include <unordered_set>

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

    unordered_set<int> st;
    vector<TreeNode*> res;

    TreeNode* createBST(TreeNode*& root, TreeNode*& node, vector<int>& container,int left, int right){
      // if(right<0 || left>container.size()-1 || left>right){
      //   return nullptr;
      // }
      if(left>right){
        return nullptr;
      }
      if(left == right){
        return new TreeNode(container[left]);
      }

      for(int i = left ; i < container.size() ; i++){
        node->val = container[i];
        st.insert(node->val);
        node->left = createBST(root,node->left,container,left,i-1);
        node->right = createBST(root,node->right,container,i+1,right);
        if(node->left) st.insert(node->left->val);
        if(node->right) st.insert(node->right->val);

        if(st.size()==container.size()){
          res.push_back(root);
        }

        st.erase(node->val);
        if(node->left) st.erase(node->left->val);
        if(node->right) st.erase(node->right->val);

      }
      // TreeNode* node;
      // node->val = container[index];
      // node->left = createBST(node->left,container,left,index-1);
      // node->right = createBST(node->right,container,index+1,right);
      

      return node;
    }

    vector<TreeNode*> generateTrees(int n) {
      vector<int> container;
      for(int i = 1; i <= n ; i++){
        container.push_back(i);
      }
      TreeNode* root = new TreeNode;
      createBST(root,root,container,0,container.size());
      return res;
    }


    // void generate(vector<vector<int>>& vect, int n ,vector<int>& container, unordered_set<int>& st){
    //   if(st.size()==n){
    //     vect.push_back(container);
    //     return;
    //   }

    //   for(int i = 1; i <= n ; i++){
    //     if(!st.count(i)){
    //       st.insert(i);
    //       container.push_back(i);
    //       generate(vect,n,container,st);
    //       st.erase(i);
    //       container.pop_back();
    //     }
    //   }

    // }

    // TreeNode* createBST(){

    // }

    // vector<TreeNode*> generateTrees(int n) {
    //   vector<TreeNode*> res;

    //   vector<vector<int>> vect;
    //   vector<int> container;
    //   unordered_set<int> st;

    //   generate(vect,n,container,st);

    //   for(auto input : vect){
    //     TreeNode* root = new TreeNode(input[0]);
        
    //   }

    //   return res;
    // }
};