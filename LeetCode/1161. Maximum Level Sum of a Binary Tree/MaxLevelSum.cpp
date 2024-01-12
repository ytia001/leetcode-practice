#include <queue>
#include <iostream>

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
    int maxLevelSum(TreeNode* root) {
      queue<TreeNode*> q;
      q.push(root);
      int res = 0;
      int depth = 0;
      int total = INT_MIN;
      while(!q.empty()){
        int size = q.size();
        cout<<size<<endl;
        int current = 0;
        depth++;
        while(size-->0){
          cout<<size<<endl;
          if(q.front()==nullptr){
            q.pop();
            continue;
          }
          current += q.front()->val;
          if(q.front()->left) q.push(q.front()->left);
          if(q.front()->right) q.push(q.front()->right);
          q.pop();
        }
        if(current>total){
          res = depth;
          total=current;
        }
      }
      return res;
    }
};

int main(){
  Solution s;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(7);
  root->right = new TreeNode(0);
  root->left->left = new TreeNode(7);
  root->left->right = new TreeNode(-8);
  cout<<s.maxLevelSum(root)<<endl;
  return 0;
}