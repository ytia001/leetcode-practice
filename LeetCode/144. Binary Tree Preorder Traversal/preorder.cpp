#include <iostream>
#include<vector>

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
private:
    vector<int> res;
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {};
        res.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return res;
    }
};

int main(){
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->right = new TreeNode(2);
  root->right->left = new TreeNode(3);
  vector<int> result = s.preorderTraversal(root);
  for(int i : result){
    cout<<i<<endl;
  }

  return 0;
}