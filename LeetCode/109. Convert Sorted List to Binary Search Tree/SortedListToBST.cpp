#include "SortedListToBST.hpp"

TreeNode* Solution::sortedListToBST(ListNode* head){
  std::vector<int> sortedVal;
  if(head == nullptr) return nullptr;
  while(head->next){
    sortedVal.push_back(head->val);
    head = head->next;
  }
  sortedVal.push_back(head->val);
  // for(int i :sortedVal) std::cout<<i<<std::endl;
  // return nullptr;
  //std::cout<<sortedVal.size()<<std::endl;
  return sortVectToBst(sortedVal,0,sortedVal.size()-1);
}

TreeNode* Solution::sortVectToBst(std::vector<int>& inputVect, int startIndex, int endIndex){
  //int mid = inputVect.size()/2;
  int noOfElem = (endIndex - startIndex)+1;
  int mid = startIndex + (noOfElem/2);
  std::cout<<mid<<std::endl;
  
  if(noOfElem==1) return new TreeNode(inputVect[startIndex]);
  if(noOfElem==2) return new TreeNode(inputVect[mid],new TreeNode(inputVect[startIndex]),nullptr);
  // std::vector<int> bottomVect(inputVect.begin(),inputVect.begin()+mid);
  // std::vector<int> upperVect(inputVect.begin()+mid+1,inputVect.end());
  return new TreeNode(inputVect[mid],sortVectToBst(inputVect,startIndex,mid-1),sortVectToBst(inputVect,mid+1,endIndex));
  
}

int main(){

  Solution s;
  ListNode* head = new ListNode(-10,new ListNode(-3,new ListNode(0,new ListNode(5, new ListNode(9)))));
  s.sortedListToBST(head);
  return 0;
}

// TreeNode* Solution::sortVectToBst(std::vector<int>& inputVect, int startIndex, int endIndex){
//   //int mid = inputVect.size()/2;
//   int mid = startIndex + ((endIndex - startIndex)+1)/2;
//   std::cout<<mid<<std::endl;
//   if(inputVect.size()==1) return new TreeNode(inputVect[startIndex]);
//   if(inputVect.size()==2) return new TreeNode(inputVect[mid],new TreeNode(startIndex),nullptr);
//   std::vector<int> bottomVect(inputVect.begin(),inputVect.begin()+mid);
//   std::vector<int> upperVect(inputVect.begin()+mid+1,inputVect.end());
//   return new TreeNode(inputVect[mid],sortVectToBst(bottomVect,0,mid-1),sortVectToBst(upperVect,mid+1,endIndex));
  
// }

// TreeNode* Solution::sortVectToBst(std::vector<int>& inputVect, int start, int end){
//   //int mid = inputVect.size()/2;
//   int mid = ((end - start)+1)/2;
//   if(inputVect.size()==1) return new TreeNode(inputVect[start]);
//   if(inputVect.size()==2) return new TreeNode(inputVect[mid],new TreeNode(start),nullptr);
//   return new TreeNode(inputVect[mid],new TreeNode(sortVectToBst(inputVect,start,mid-1)),new TreeNode(sortVectToBst(inputVect,mid+1,end)));
  
  
// }