#include "LinkedListCycleII.hpp"

ListNode *Solution::detectCycle(ListNode *head){
  // std::cout<<":asd"<<std::endl;
  std::unordered_map<ListNode*,int> addToPos;
  int currPos = 0;
  int beginPos = -1;
  ListNode* beginListNode = nullptr;
  if(!head) return NULL;
  while(head->next){
    if(auto search = addToPos.find(head); search !=addToPos.end()){
      beginPos = search->second;
      beginListNode = search->first;
      break;
    }
    //addToPos[head->next] = ++currPos;
    addToPos[head] = ++currPos;
    head = head -> next;
  }

  if(!beginListNode) return NULL;
  return beginListNode;
}

int main(){

  Solution s1;
  ListNode* test = new ListNode(1);
  test->next = new ListNode(2);
  test->next->next = test->next;
  s1.detectCycle(test);
  return 0;
}

// ListNode *detectCycle(ListNode *head) {
//         std::unordered_map<ListNode*,int> addToPos;
//         int currPos = 0;
//         int beginPos = -1;
//         ListNode* beginListNode = nullptr;

//         while(head->next){
//             if(auto search = addToPos.find(head->next); search !=addToPos.end()){
//             beginPos = search->second;
//             beginListNode = search->first;
//             break;
//             }
//             addToPos[head->next] = ++currPos;
//             head = head -> next;
//         }
     
//         if(!beginListNode) return NULL;
//         return beginListNode;
//     }