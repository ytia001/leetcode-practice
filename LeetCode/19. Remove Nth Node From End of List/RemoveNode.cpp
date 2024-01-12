
 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* removeNthFromEndTest(ListNode* head, int n) {
        ListNode* firstPtr = head;
        while(--n>0){
          firstPtr = firstPtr->next;
        }
        ListNode* secPtr = new ListNode(0,head);
        while(firstPtr!=nullptr && firstPtr->next!=nullptr){
          firstPtr = firstPtr->next;
          secPtr = secPtr ->next;
        }
        if(secPtr->next==head){
          head = secPtr->next->next;
        }else{
          secPtr->next = secPtr->next->next;
        }

        return head;
    }


    ListNode* removeNthFromEndTest(ListNode* head, int n) {
        ListNode* firstPtr = head;
        while(--n>0){
          firstPtr = firstPtr->next;
        }
        ListNode* secPtr = new ListNode(0,head);
        //ListNode* secPtr = head;
        while(firstPtr!=nullptr && firstPtr->next!=nullptr){
          firstPtr = firstPtr->next;
          secPtr = secPtr ->next;
        }
        // if(secPtr->next == nullptr){
        //   secPtr = nullptr;
        // }
        // else if(secPtr->next != nullptr){
        //   secPtr->next = secPtr->next->next;
        // }
        if(secPtr->next==head){
          head = secPtr->next->next;
        }else{
          secPtr->next = secPtr->next->next;
        }

        return head;
    }
};