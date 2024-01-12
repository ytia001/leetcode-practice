#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <iostream>

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

    void inorder(TreeNode* node, unordered_map<int,int>& countMap){
      if(!node){
        return;
      }
      inorder(node->left,countMap);
      countMap[node->val]++;
      inorder(node->right,countMap);
      return;
    }

    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        unordered_map<int,int> countMap;
        inorder(root,countMap);
       
        int max = INT_MIN;
        for(auto k : countMap){
          int count = k.second;
          if(count>max){
            res.clear();
            res.push_back(k.first);
            max = k.second;
          }else if (count==max){
            res.push_back(k.first);
          }
        }
        return res;
    }
};