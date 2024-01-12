#include <iostream>
#include <vector>

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
    TreeNode* newRoot;
    TreeNode* currPointer;

    TreeNode* increasingBST(TreeNode* root) {
      if(!root){
        return nullptr;
      }
  
      increasingBST(root->left);
      TreeNode* currNode = new TreeNode(root->val);
      //int currNode = root->val;
      if(!newRoot){
        //newRoot = new TreeNode(currNode);
        newRoot = currNode;
        currPointer = newRoot;
      }else{
        //cout<<"asd"<<endl;
        //currPointer->right = new TreeNode(currNode);
        currPointer->right = currNode;
        currPointer = currPointer->right;
      }
      increasingBST(root->right);

      return newRoot;
    }  

     void inorder(TreeNode* root,vector<int>& container) {
      if(!root){
        return;
      }
      inorder(root->left,container);
      container.push_back(root->val);
      inorder(root->right,container);
      return;
    }  

    TreeNode* increasingBST2(TreeNode* root) {
        TreeNode* resNode;
        TreeNode* ptr;
        vector<int> container;
        inorder(root,container);
      
        for( int i = 0 ; i < container.size() ; i++){
          if(i==0){
            resNode = new TreeNode(container[i]);
            ptr = resNode;
          }else{
            ptr->right = new TreeNode(container[i]);
            ptr = ptr->right;
          }
        }
        
        return resNode;
    }

    TreeNode* increasingBSTTest1(TreeNode* root) {
      if(!root){
        return nullptr;
      }
      TreeNode* leftNode = increasingBST(root->left);
      int nodeVal = root->val;
      TreeNode* rightNode = increasingBST(root->right);
      return new TreeNode();
    }

    TreeNode* increasingBSTTest(TreeNode* root) {
      if(!root->left && !root->right){
        return new TreeNode(root->val);
      }else if(!root->left){
        return new TreeNode(root->val,nullptr,new TreeNode(root->right->val));
      }else if (!root->right){
        return new TreeNode(root->left->val,nullptr,new TreeNode(root->val));
      }
      TreeNode* leftNode = increasingBST(root->left);
      TreeNode* currNode = new TreeNode (root->val);
      TreeNode* rightNode = increasingBST(root->right);

      leftNode->right = currNode;
      leftNode->right->right = rightNode;
      return leftNode;
    }

     TreeNode* increasingBSTTest2(TreeNode* root) {
      if(!root->left && !root->right){
        return new TreeNode(root->val);
      }
      // else if(!root->left){
      //   return new TreeNode(root->val,nullptr,new TreeNode(root->right->val));
      // }else if (!root->right){
      //   return new TreeNode(root->left->val,nullptr,new TreeNode(root->val));
      // }
      TreeNode* leftNode = increasingBST(root->left);
      TreeNode* currNode = new TreeNode (root->val);
      TreeNode* rightNode = increasingBST(root->right);

      leftNode->right = currNode;
      leftNode->right->right = rightNode;
      return leftNode;
    }

    

  
};

int main(){
  Solution s;
  TreeNode* root = new TreeNode(5); // Create root node with value 5
  root->left = new TreeNode(3); // Create left child of root with value 3
  root->right = new TreeNode(6); // Create right child of root with value 6
  root->left->left = new TreeNode(2); // Create left child of node with value 2
  root->left->right = new TreeNode(4); // Create right child of node with value 4
  root->right->right = new TreeNode(8); // Create right child of node with value 8
  root->left->left->left = new TreeNode(1); // Create left child of node with value 1
  root->right->right->left = new TreeNode(7); // Create left child of node with value 7
  root->right->right->right = new TreeNode(9); // Create right child of node with value 9

  TreeNode* test = s.increasingBST2(root);
  while(test){
    cout<<test->val<<endl;
    test = test->right;
  }

  return 0;
}