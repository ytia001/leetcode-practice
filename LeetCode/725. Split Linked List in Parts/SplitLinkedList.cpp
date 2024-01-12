#include <vector>

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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
      vector<ListNode*> res;
      int count = 0;

      ListNode* ptr = head;
      while(ptr){
        count++;
        ptr = ptr->next;
      }

      int size = 0;
      int left = 0;
      
      if(count<=k){
        size = 1;
      }else{
        size = count/k;
        left = count%k;
      }
        

      ptr = head;
      for(int i = 0; i < k ; i++ ){
        if(!ptr){
          res.push_back(nullptr);
        }else{
          ListNode* dummyPtr = ptr;
          if(left >= 1){
            dummyPtr = dummyPtr->next;
            left--;
          }
          for(int i = 0 ; i < size - 1 ; i++){
            dummyPtr = dummyPtr->next;
          }
          res.push_back(ptr);
          ptr = dummyPtr->next;
          dummyPtr->next = nullptr;
        }
      }

      return res;  
    }
};