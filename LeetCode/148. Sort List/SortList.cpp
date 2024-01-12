#include <queue>

using namespace std;


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

    void sort(ListNode* node,priority_queue<int,vector<int>,less<>>& pq){
      if(!node) return;
      pq.push(node->val);
      sort(node->next,pq);
      node->val = pq.top();
      pq.pop();
      return;
    }


    ListNode* sortList(ListNode* head){
      priority_queue<int,vector<int>,less<>> pq;  
      sort(head,pq);
      return head;
    }
};