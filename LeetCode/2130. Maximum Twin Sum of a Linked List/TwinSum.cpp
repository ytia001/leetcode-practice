#include <vector>
#include <iostream>
#include <algorithm>

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

    int Answer(ListNode* head) {
      ListNode* slow = head;
      ListNode* fast = head;
      int maxVal = 0;

      // Get middle of linked list
      while(fast && fast -> next)
      {
        fast = fast -> next -> next;
        slow = slow -> next;
      }

      // Reverse second part of linked list
      ListNode *nextNode, *prev = NULL;
      while (slow) {
        nextNode = slow->next;
        slow->next = prev;
        prev = slow;
        slow = nextNode;
      }

      // Get max sum of pairs
      while(prev)
      {
        maxVal = max(maxVal, head -> val + prev -> val);
        prev = prev -> next;
        head = head -> next;
      }

      return maxVal;
    }

    int pairSum(ListNode* head) {
       vector<int> pairMax;
       int n = -1;
       ListNode* twoPtr = head;
       ListNode* onePtr = head;
       while(twoPtr != NULL || onePtr != NULL){
          if(twoPtr == NULL){
            pairMax[n--] += onePtr->val;
            //cout<<pairMax[n+1]<<endl;
            onePtr = onePtr -> next;
          }else{
            pairMax.push_back(onePtr->val);
            //cout<<onePtr->val<<endl;
            n++;
            twoPtr = twoPtr -> next -> next;
            onePtr = onePtr -> next;
          }
       }

       return *max_element(pairMax.begin(),pairMax.end());
    }

    int pairSumTest(ListNode* head) {
       vector<int> pairMax;
       int n = -1;
       ListNode* twoPtr = head;
       ListNode* onePtr = head;
       while(twoPtr != NULL ){
          pairMax.push_back(onePtr->val);
            n++;
            twoPtr = twoPtr -> next -> next;
            onePtr = onePtr -> next;
       }
       
      while(onePtr!=NULL){
          pairMax[n--] += onePtr->val;
          //cout<<pairMax[n+1]<<endl;
          onePtr = onePtr -> next;
      }
       

       return *max_element(pairMax.begin(),pairMax.end());
    }
};

int main(){
  Solution s;
  ListNode* head = new ListNode(1);
  head->next = new ListNode(1000);
  head->next->next = new ListNode(2);
  head->next->next->next = new ListNode(3);
  //head->next->next->next->next = new ListNode(5);
  cout<<s.pairSum(head)<<endl;
  return 0 ;
}