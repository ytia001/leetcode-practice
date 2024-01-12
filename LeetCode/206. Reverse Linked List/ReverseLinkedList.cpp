
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

    ListNode* reverseListTest2(ListNode* head) {
        if(!head) return head;
        ListNode* prevNode = nullptr;
        ListNode* nextPtr = head->next;
        head->next = prevNode;
        while(nextPtr){ 
          prevNode = head;
          head = nextPtr; 
          nextPtr = head->next;
          head->next = prevNode;
        }
        return head;
    }

    ListNode* reverseListTest(ListNode* head) {
        if(!head) return head;
        ListNode* prevNode = nullptr;
        // ListNode* currPtr = head;
        ListNode* nextPtr = head->next;
        while(nextPtr){ 
          head->next = prevNode;
          prevNode = head;
          head = nextPtr;
          nextPtr = head->next;
        }
        head->next = prevNode;
        return head;
    }
};