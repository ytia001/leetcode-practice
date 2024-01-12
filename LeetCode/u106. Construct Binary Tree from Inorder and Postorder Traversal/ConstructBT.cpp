#include "ConstructBT.hpp"

 TreeNode* Solution::buildTree(std::vector<int>& inorder, std::vector<int>& postorder){
    int rootVal = postorder[postorder.size()-1];
    auto it = std::find(inorder.begin(),inorder.end(),rootVal);
    int indexRoot = std::distance(inorder.begin(),it);
    return new TreeNode(inorder[indexRoot],makeTree(inorder,0,indexRoot-1),makeTree(inorder,indexRoot+1,inorder.size()-1));
 }

 TreeNode* makeTree(std::vector<int> inputValues,int left, int right){
    int mid = left + (right -left)/2;
    int size = (left-right)+1;
    // if(size==3) return new TreeNode(inputValues[mid],new TreeNode(inputValues[mid-1]),new TreeNode(inputValues[mid+1]));
    // if(size==2){

    // }
    if(size==1) return new TreeNode(inputValues[left]);
    if(mid==left) return new TreeNode(inputValues[mid],nullptr,new TreeNode(inputValues[right]));
    return new TreeNode(inputValues[mid],makeTree(inputValues,left,mid-1),makeTree(inputValues,mid+1,right));
 }