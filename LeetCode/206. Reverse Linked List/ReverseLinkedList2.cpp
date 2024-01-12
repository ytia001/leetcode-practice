
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

    ListNode* reverse(ListNode* start){
      if(!start || !start->next) return start;
      ListNode* newStart = reverse(start->next);
      newStart->next = start;
      newStart = newStart->next;
      return newStart;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* start = head;
        while(head && head->next){
          head = head->next;
        }
        reverse(start);
        return head;
    }

    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* start = head;
        ListNode* middle = head->next;
        ListNode* end;
        start->next = nullptr;
        while(middle && middle->next){
          end = middle->next;
          middle->next = start;
          start = middle;
          middle = end;
        }
        middle->next = start;
        return middle;
    }

};