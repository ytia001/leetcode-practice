#include <iostream>
#include <queue>

using namespace std;


//Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
      priority_queue<int,vector<int>,greater<>> pq;
      if(list1==nullptr || list2 == nullptr){
        if(list1==nullptr) return list2;
        if(list2==nullptr) return list1;
      }else if(list1==nullptr && list2 == nullptr){
        return nullptr;
      }
      while(list1 || list2){
        if(list1) {
          pq.push(list1->val);
          list1 = list1 ->next;
        }
        if(list2){
          pq.push(list2->val);
          list2 = list2 ->next;
        }
     }
     ListNode* res = new ListNode(pq.top());
     ListNode* copy = res;
     pq.pop();
     while(!pq.empty()){
      copy -> next = new ListNode(pq.top());
      pq.pop();
      copy = copy -> next;
     }
     return res;
    }
    // ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    //   ListNode* smallPtr;
    //   ListNode* largePtr;
    //   (list1->val >= list2->val) ? smallPtr = list2 , largePtr = list1 : smallPtr = list1 , largePtr = list2;
    //   ListNode* res = smallPtr;
    //   for(  ; smallPtr!= nullptr || smallPtr->next!=nullptr ; smallPtr = smallPtr->next){
    //     int target = smallPtr->next->val;
    //     cout<<target<<endl;
    //     for(  ; largePtr!=nullptr;  largePtr = largePtr->next){
    //       if(largePtr->val<=target){
    //         ListNode* dummy = largePtr;
    //         ListNode* nextNode = smallPtr -> next;
    //         smallPtr->next = dummy;
    //         cout<<"as: "<<smallPtr->next->val<<endl;
    //         smallPtr->next->next = nextNode;
    //         cout<<"as12: "<<smallPtr->next->val<<endl;
    //         smallPtr = smallPtr ->next;
    //       }else{
    //         break;
    //       }
    //     }
    //     cout<<"Dfsdf"<<endl;
    //     if(largePtr==nullptr) break;
    //   }
    //   return res;
    // }


    // ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    //     ListNode* lPtr1 ; 
    //     ListNode* lPtr2;
    //     ListNode* sPtr;
    //     (list1->val >= list2->val) ? lPtr1 = list1 , sPtr = list2 : lPtr1 = list2 , sPtr = list1;
    //     // for( ; start==nullptr || start->next == nullptr; start = start->next ){
    //     //   int target = start->next->val;
    //     //   while(ptr!=nullptr && ptr->val<=target){
    //     //     ptr = ptr-
    //     //   }
    //     // }
    //     lPtr2 = lPtr1;
    //     while(lPtr2->next != nullptr && sPtr->next != nullptr){
    //       ListNode* target = sPtr->next;
    //       if(lPtr2->val<target->val){
    //         lPtr2 = lPtr2->next;
    //         continue;
    //       }
    //       ListNode* dummy = lPtr2;
    //       sPtr->next = lPtr2;

    //     }
    // }
};

int main(){
  Solution s;
  ListNode* l1 = new ListNode(1,new ListNode(2, new ListNode(4)));
  ListNode* l2 = new ListNode(1,new ListNode(3, new ListNode(4)));
  ListNode* res = s.mergeTwoLists(l1,l2);
  while(res){
    cout<<res->val<<endl;
    res =res ->next;
  }
  return 0;
}