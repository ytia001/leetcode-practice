#include <iostream>
#include <stack>

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

    ListNode* Answer(ListNode* head, int k) {
      ListNode *n1 = nullptr, *n2 = nullptr;
      for (auto p = head; p != nullptr; p = p->next) {
          n2 = n2 == nullptr ? nullptr : n2->next;
          if (--k == 0) {
              n1 = p;
              n2 = head;
          }
      }
    // The problem description specifically asks to swap values, not nodes themselves. 
      swap(n1->val, n2->val);
      return head;
  }
   
     ListNode* swapNodes2(ListNode* head, int k) {
        int swapIndicator = k - 1;
        int n = 0;
        ListNode* copy = head;
        ListNode* firstPtr = head;
        ListNode* secPtr = head;
        while(copy){
          if(swapIndicator>0){
            firstPtr = firstPtr->next;
          }
          swapIndicator--;
          n++;
          copy = copy->next;
        }
        // cout<<"n: "<<n<<endl;
        swapIndicator = (n+1)-k-1;
        // cout<<"back: "<<swapIndicator<<endl;
        while(swapIndicator!=0){
          secPtr = secPtr->next;
          swapIndicator--;
        }
        
        int temp = firstPtr->val;
        firstPtr->val = secPtr->val;
        secPtr->val = temp;

        // cout<<firstPtr->val<<endl;
        // cout<<secPtr->val<<endl;
        return head;
    }


     ListNode* swapNodes2(ListNode* head, int k) {
        int swapIndicator = k - 1;
        int n = 0;
        ListNode* copy = head;
        ListNode* firstPtr = head;
        ListNode* secPtr = head;
        while(copy){
          if(swapIndicator>0){
            firstPtr = firstPtr->next;
          }
          swapIndicator--;
          n++;
          copy = copy->next;
        }
        // cout<<"n: "<<n<<endl;
        swapIndicator = (n+1)-k-1;
        // cout<<"back: "<<swapIndicator<<endl;
        while(swapIndicator!=0){
          secPtr = secPtr->next;
          swapIndicator--;
        }
        
        int temp = firstPtr->val;
        firstPtr->val = secPtr->val;
        secPtr->val = temp;

        // cout<<firstPtr->val<<endl;
        // cout<<secPtr->val<<endl;
        return head;
    }


    ListNode* swapNodes(ListNode* head, int k) {
        int swapIndicator = k - 1;
        //int n = 1;
        stack<ListNode*> s;
        ListNode* copy = head;
        ListNode* firstPtr = head;
        ListNode* secPtr = NULL;
        while(copy){
          if(swapIndicator>0){
            firstPtr = firstPtr->next;
          }
          swapIndicator--;
          //n++;
          s.push(copy);
          copy = copy->next;
        }
        //swapIndicator = (n+1)-k-1;
        swapIndicator = k-1;
        //cout<<swapIndicator<<endl;
        while(swapIndicator!=0){
          s.pop();
         // secPtr = secPtr->next;
          swapIndicator--;
        }
        secPtr = s.top();
        
        int temp = firstPtr->val;
        firstPtr->val = secPtr->val;
        secPtr->val = temp;

        // cout<<firstPtr->val<<endl;
        // cout<<secPtr->val<<endl;
        return head;
    }


    // ListNode* swapNodesTest(ListNode* head, int k) {
    //     int n = 1;
    //     int swapIndicator = k - 1;
    //     ListNode* copy = head;
    //     ListNode* firstPtr = head;
    //     ListNode* secPtr = head;
    //     while(!head){
    //       if(swapIndicator>0){
    //         firstPtr = firstPtr->next;
    //       }
    //       swapIndicator--;
    //       n++;
    //       head = head->next;
    //     }
    //     swapIndicator = (n+1)-k;
    //     while()

    //     cout<<firstPtr->val<<endl;
    //     return head;
    // }
};

int main(){

  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  Solution s;
  ListNode* test = s.swapNodes2(head,4);
  while(test){
    cout<<test->val<<endl;
    test = test->next;
  }
  return 0;
}