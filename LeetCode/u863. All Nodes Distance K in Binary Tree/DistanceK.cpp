#include <stack>
#include <unordered_map>
#include <vector>
#include <queue>
#include <unordered_set>

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


    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
      vector<int> res;
      unordered_map<TreeNode*,vector<TreeNode*>> mp;
      queue<TreeNode*> q;
      q.push(root);
      while(!q.empty()){
        int size = q.size();
        while(size-->0){
          TreeNode* node = q.front(); q.pop();
          if(node->left){
            mp[node].push_back(node->left);
            mp[node->left].push_back(node);
            q.push(node->left);
          }
          if(node->right){
            mp[node].push_back(node->right);
            mp[node->right].push_back(node);
            q.push(node->right);
          }
        }
      }
      queue<TreeNode*> q2;
      unordered_set<TreeNode*> st;
      q2.push(target);
      while(k-->0){
        int size = q2.size();
        while(size-->0){
          TreeNode* node = q2.front(); q2.pop();
          for(auto& i: mp[node]){
            if(!st.count(i)){
              
            }
          }
        }
      }

    }

    // void transfer(TreeNode* root, TreeNode* target, int depth , int k , vector<int>& res){
    //   if(!root) return;
    //   transfer(root->left,target,depth+1,k,res);
    //   transfer(root->right,target,depth+1,k,res);
    //   if(depth==k && root!=target){
    //     res.push_back(root->val);
    //   }
    // }

    // int search(TreeNode* root, TreeNode* target, int depth){
    //   if(!root) return 0;
    //   search(root->left,target,depth+1);
    //   search(root->right,target,depth+1);
    //   if(root==target) return depth;
    // }

    // vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    //   int targetDepth = search(root,target,0);
    //   vector<int> res;
    //   if(k-targetDepth>=0) transfer(root,target,0,k-targetDepth,res);
    //   transfer(root,target,0,k,res);
    //   return res;
    // }

};