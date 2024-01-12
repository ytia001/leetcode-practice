#include <iostream>
#include <algorithm>

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
 
class Answer {
private:
    int maxLen = 0;
public:
    int longestZigZag(TreeNode* root) {
        if (!root) return 0;
        path(root->left, 0, false);
        path(root->right, 0, true);
        return maxLen;
    }
    
    void path(TreeNode* node, int depth, bool direction) {
        maxLen = max(maxLen, depth);
        if (!node) return;
        path(node->left, (direction) ? depth+1 : 0, false);
        path(node->right, (!direction) ? depth+1 : 0, true);
    }
};

class Solution {
public:
    int longestZigZag(TreeNode* root) {
      if(!root) return 0;
      int left = longestZigZag(root->left);
      int center = zigzagNode(root);
      int right = longestZigZag(root->right);
      return max(max(left,center),right);
    }

    int zigzagNode(TreeNode* root) {
      return max(zigzag(root->left,1),zigzag(root->right,-1));
    }

    int zigzag(TreeNode* root,int dir){
        if(!root){
          return 0;
        }
        if(dir==1){
          return 1 + zigzag(root->right,-1);
        }else{
          return 1 + zigzag(root->left,1);
        }
        return -1;
    }


  

};

int main(){
  
  TreeNode* root = new TreeNode(1);
  root->left = nullptr;
  root->right = new TreeNode(1);
  root->right->left = new TreeNode(1);
  root->right->right = new TreeNode(1);
  root->right->left->left = nullptr;
  root->right->left->right = nullptr;
  root->right->right->left = nullptr;
  root->right->right->right = new TreeNode(1);
  root->right->right->right->left = nullptr;
  root->right->right->right->right = nullptr;
  // root->left = new TreeNode(1);
  // root->right = new TreeNode(1);

  Solution s;
  cout<<s.longestZigZag(root)<<endl;
  return 0;
}