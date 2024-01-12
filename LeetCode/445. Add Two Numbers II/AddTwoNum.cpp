#include <string>

using namespace std;

//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:

    // ListNode* joinList(string strL1,string strL2,int index, int& overload){
    //   ListNode* head;
    //   if(index >= strL1.size() && index >= strL2.size()){
    //     return NULL;
    //   }else if(index >= strL1.size() || index >= strL2.size()){
    //     if(index >= strL1.size()){
    //       head->val = (overload + strL2[index]);
    //       overload = (strL2[index])/10;
    //       head = joinList(strL1,strL2,index+1,overload);
    //     }else{
    //       head->val = (overload + strL1[index]);
    //       overload = (strL1[index])/10;
    //       head = joinList(strL1,strL2,index+1,overload);
    //     }
    //   }else{
    //     head->val = (overload + (strL1[index] + strL2[index])%10);
    //     overload = (strL1[index]+strL2[index])/10;
    //     head = joinList(strL1,strL2,index+1,overload);
    //   }

    //   return head;
    // }
    
     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      string strL1 , strL2;
      while(l1 || l2){
        if(l1) {
          strL1 = to_string(l1->val) + strL1;
          l1 = l1->next;
        }
        if(l2) {
          strL2 = to_string(l2->val) + strL2;
          l2 = l2->next;
        }
      }

      ListNode* head = new ListNode();
      int size = (strL1.size()>=strL2.size())? strL1.size() : strL2.size();
      int overload = 0;
      int i = 0;
      while(i < size || overload==1){
        ListNode* beforeHead = new ListNode();
        beforeHead -> next = head;
        int no1 = (i>= strL1.size())? 0 : strL1[i]-'0';
        int no2 = (i>= strL2.size())? 0 : strL2[i]-'0';
        head->val = (overload + no1 + no2)%10;
        overload = (overload + no1 + no2) >= 10 ? 1 : 0;
        head = beforeHead;
        i++;
      }

      return head->next;
    }
};