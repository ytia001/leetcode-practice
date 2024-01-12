#include "SymmetricTree.hpp"

 bool Solution::isSymmetric(TreeNode* root){
    if(root == nullptr) return false;
    std::vector<int> vect;
    inorderSearchLeft(vect,root->left);
    inorderSearchRight(vect,root->right);
    for ( int i : vect) std::cout<<i<<" ";
    int size = vect.size();
    if(size%2!=0 || size <=2) return false;
    for(int i = 0 ; i < (size-1)/2 ; i++){
      if(vect[i] == vect[size-1-i]){
        continue;
      }else{
        return false;
      }
    }
    return true;
 }

 void Solution::inorderSearchLeft(std::vector<int>& inorderVect,TreeNode* root){
  if(root == nullptr) return;

  inorderSearchLeft(inorderVect,root->left);
  if(root->left == nullptr && root->right != nullptr){
     inorderVect.push_back(101); 
     inorderVect.push_back(root->val); 
  }else if (root->right == nullptr && root->left != nullptr){
     inorderVect.push_back(root->val); 
     inorderVect.push_back(101); 
  }else{
     inorderVect.push_back(root->val); 
  }
  inorderSearchLeft(inorderVect,root->right);
  return;
 }

 void Solution::inorderSearchRight(std::vector<int>& inorderVect,TreeNode* root){
  if(root == nullptr) return;

  inorderSearchRight(inorderVect,root->right);
  if(root->left == nullptr && root->right != nullptr){
     inorderVect.push_back(root->val); 
     inorderVect.push_back(101); 
     
  }else if (root->right == nullptr && root->left != nullptr){
     inorderVect.push_back(101); 
     inorderVect.push_back(root->val); 
     
  }else{
     inorderVect.push_back(root->val); 
  }
  inorderSearchRight(inorderVect,root->left);
  return;
 }


  int main(){
    Solution s;
    //TreeNode* root = new TreeNode(1,new TreeNode(2,new TreeNode(3),new TreeNode(4)),new TreeNode(2,new TreeNode(4), new TreeNode(3)));
    //TreeNode* root = new TreeNode(1,new TreeNode(2,new TreeNode(2),nullptr),new TreeNode(2,new TreeNode(2),nullptr));
    //TreeNode* root = new TreeNode(1,new TreeNode(2,nullptr,new TreeNode(3)),new TreeNode(2,new TreeNode(3),nullptr));
    //TreeNode* root = new TreeNode(1,new TreeNode(0),nullptr);
    TreeNode* root = new TreeNode(5, new TreeNode(4,  nullptr, new TreeNode(1,new TreeNode(2), nullptr )), new TreeNode(1, nullptr, new TreeNode(4,new TreeNode(2), nullptr )));
    std::cout<<s.isSymmetric(root)<<std::endl;
    //s.isSymmetric(root);
    return 0;
  }

  // bool Solution::isEqual(TreeNode* nodeL , TreeNode* nodeR){
  //   if(nodeL==nullptr || nodeR == nullptr) return;
  //   int valL= nodeL->val;
  //   int valR= nodeR->val;
  //   if(valL==valR) return true;
  //   bool firstCond = isEqual(nodeL->left,nodeR->right);
  //   bool secondCond = isEqual(nodeL->right,nodeR->left);
  //   if(firstCond && secondCond) return true;
  //   return false;
//  }

//solution 1
// bool isSymmetric(TreeNode *root) {
//         TreeNode *left, *right;
//         if (!root)
//             return true;       
//         queue<TreeNode*> q1, q2;
//         q1.push(root->left);
//         q2.push(root->right);
//         while (!q1.empty() && !q2.empty()){
//             left = q1.front();
//             q1.pop();
//             right = q2.front();
//             q2.pop();
//             if (NULL == left && NULL == right)
//                 continue;
//             if (NULL == left || NULL == right)
//                 return false;
//             if (left->val != right->val)
//                 return false;
//             q1.push(left->left);
//             q1.push(left->right);
//             q2.push(right->right);
//             q2.push(right->left);
//         }
//         return true;
//     }

//Solution 2
// class Solution {
// public:
//     bool isSymmetric(TreeNode* root) {
//         return root == nullptr || isSymmetricHelp(root->left, root->right);
//     }
//     bool isSymmetricHelp(TreeNode* left, TreeNode* right) {
//         if (left == nullptr || right == nullptr)
//             return left == right;
//         if (left->val != right->val)
//             return false;
//         return isSymmetricHelp(left->left, right->right) && isSymmetricHelp(left->right, right->left);
//     }
// };
