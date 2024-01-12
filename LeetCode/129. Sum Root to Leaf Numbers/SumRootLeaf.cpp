#include "SumRootLeaf.hpp"

int Solution::sumNumbers(TreeNode* root){
  std::vector<int> sumRootTree;
  int totalSum = 0;
  sumPreOrder(sumRootTree,root);
  for(int i : sumRootTree){
    totalSum += i;
    std::cout<<i<<"  "<<std::endl;
  }
  return totalSum;
}

void Solution::sumPreOrder(std::vector<int>& sumRootTree, TreeNode* root, int currSum){
  if(root==nullptr){
    return;
  }else if (root->left == nullptr && root->right == nullptr){
    // currSum = currSum*10 + root->val;
    sumRootTree.push_back(currSum*10 + root->val);
    currSum = 0;
    return;
  }else{
    currSum = currSum*10 + root->val;
  }
  sumPreOrder(sumRootTree,root->left,currSum);
  sumPreOrder(sumRootTree,root->right,currSum);
}

int main(){
  Solution s;
  TreeNode* testRoot = new TreeNode(4,new TreeNode(9,new TreeNode(5),new TreeNode(1)),new TreeNode(0));
  //TreeNode* testRoot = new TreeNode(1,new TreeNode(2),nullptr);
  std::cout<<s.sumNumbers(testRoot)<<std::endl;

}