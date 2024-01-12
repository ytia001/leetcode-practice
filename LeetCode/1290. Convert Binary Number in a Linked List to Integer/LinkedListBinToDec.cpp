#include "LinkedListBinToDec.hpp"
 
//Solution
// FOR changing "123" to DEC
// Loop	Character	Operation	  Result
// 1	    ‘1’	        1	          1
// 2	    ‘2’	        (1x10) + 2	  12
// 3	    ‘3’	        (12*10) + 3	  123

// FOR changing 101 to BINARY
// Loop	Character	Operation	  Result
// 1	    ‘1’	        1	          1
// 2	    ‘0’	        (1x2) + 0	  2
// 3	    ‘1’	        (2*2) + 1	  5
int Solution::getDecimalValueSoln(ListNode* head){
  int sum = 0;

  while(head != nullptr){
    sum *= 2;
    sum += head->val;
    head = head->next;
  }
  return sum;
}

// attempted answer
 void Solution::binToDec(ListNode* head,std::vector<int>& binVect){
 
    if(!head->next){
      binVect.push_back(head->val);
      return;
    } 
    binToDec(head->next,binVect);
    binVect.push_back(head->val);
    return;
  }

int Solution::getDecimalValue(ListNode* head){
  std::vector<int> binVect;
  binToDec(head,binVect);
  int total = 0;
  for (int i =0 ; i < binVect.size() ; i++){
    total += binVect[i] * pow(2,i);
  }
  return total;
}

int main(){
  ListNode* head = new ListNode(1,new ListNode(0,new ListNode(1)));
  Solution s1;
  std::cout<<s1.getDecimalValueSoln(head)<<std::endl;
  return 0;
}

// int Solution::binToDec(ListNode* head){
// std::vector<int> binVect;

// if(!head->next){
//   // binVect.push_back(head->val);
//   // int total = 0;
//   // for (int i = 0 ; i<binVect.size() ; i++){
//   //   total += binVect[i] * pow(2,binVect.size()-1-i);
//   // }
//   return;
// }
// binVect.push_back(head->val);
// binToDec(head->next);
// return total;
// }




// int Solution::binToDec(ListNode* head){
// std::vector<int> binVect;

// if(!head->next){
//   binVect.push_back(head->val);
//   int total = 0;
//   for (int i = 0 ; i<binVect.size() ; i++){
//     total += binVect[i] * pow(2,binVect.size()-1-i);
//   }
//   return total;
// }
// binVect.push_back(head->val);
// binToDec(head->next);
// return total;
// }