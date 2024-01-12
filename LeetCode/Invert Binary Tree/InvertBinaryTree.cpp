#include"InvertBinaryTree.hpp"

// struct TreeNode {
//           int val;
//         TreeNode *left;
//         TreeNode *right;
//         TreeNode() : val(0), left(nullptr), right(nullptr) {}
//         TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//         TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//       };

TreeNode* Solution::invertTree(TreeNode* root){

if ( !root ) return nullptr;
return new TreeNode(root->val,Solution::invertTree(root->right),Solution::invertTree(root->left));

}

// solution
//  if(root==NULL)return NULL;
//         invertTree(root->left);
//         invertTree(root->right);
//         TreeNode* temp=root->left;
//         root->left=root->right;
//         root->right=temp;

//         return root;

int main(){

  // std::vector<int> vectOut;
  // for ( int i =0 ; i < 9 ; i ++) vectOut.push_back(i);
  // for (int i = 0; i < 9 ; i ++) std::cout<< vectOut.at(i) << std::endl;
  return 0;
}