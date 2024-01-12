#include <iostream>
#include <algorithm>
#include <queue>

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
    // void search(TreeNode* root,int& res, int prevVal){
    //   if(!root) return;
    //   // res = min(res,abs(search(root->left,res)-root->val));
    //   // res = min(res,abs(search(root->left,res)-root->val));
    //   search(root->left,res,root->val);
    //   res = min(res,abs(prevVal-root->val));
    //   search(root->right,res,root->val);
    // }

    // void cal (queue<int>& q, int i,int& res){
    //   if(q.size()<=2){
    //     q.push(i);
    //   }else{

    //   }
    // }

    void search(TreeNode* root,queue<int>& q,int& res){
      if(!root) return;
      search(root->left,q,res);
      if(q.size()<=2){
        q.push(root->val);
      }else{
        int front = q.front();
        q.pop();
        res = min(res,abs(front-q.front()));
        q.push(root->val);
      }
      search(root->right,q,res);
    }

    int getMinimumDifference(TreeNode* root) {
      queue<int> q;
      int res = INT_MAX;
      search(root,q,res);

      int front = q.front();
      q.pop();
      res = min(res,abs(front-q.front()));
      return res;
    }
};