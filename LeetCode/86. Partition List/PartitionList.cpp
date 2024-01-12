
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
    ListNode* partition(ListNode* head, int x) {
      if(!head) return head;
      
      ListNode* lessNodes = new ListNode();
      ListNode* moreNodes = new ListNode();
      ListNode* dummyLess = lessNodes;
      ListNode* dummyMore = moreNodes;

      while(head){
        if(head->val < x){
          dummyLess->next = new ListNode(head->val);
          dummyLess = dummyLess->next;
        }else{
          dummyMore->next = new ListNode(head->val);
          dummyMore = dummyMore->next;
        }
        head = head->next;
      }

      dummyLess -> next = moreNodes->next;
      return lessNodes->next;
    }

    
};