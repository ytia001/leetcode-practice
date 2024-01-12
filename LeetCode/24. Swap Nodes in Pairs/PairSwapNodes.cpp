#include <iostream>

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

    ListNode* Answer2(ListNode* head) {
        if(!head || !head->next) return head; //If there are less than 2 nodes in the given nodes, then no need to do anything just return the list as it is.
		
        ListNode* dummyNode = new ListNode();
        
        ListNode* prevNode=dummyNode;
        ListNode* currNode=head;
        
        while(currNode && currNode->next){
            prevNode->next = currNode->next;
            currNode->next = prevNode->next->next;
            prevNode->next->next = currNode;
            
            prevNode = currNode;
            currNode = currNode->next;
        }
        
        return dummyNode->next;
    }

    ListNode* Answer1(ListNode* head) {
        // if head is NULL OR just having a single node, then no need to change anything 
        if(head == NULL || head -> next == NULL) 
        {
            return head;
        }
            
        ListNode* temp; // temporary pointer to store head -> next
        temp = head->next; // give temp what he want
        
        head->next = swapPairs(head->next->next); // changing links
        temp->next = head; // put temp -> next to head
        
        return temp; // now after changing links, temp act as our head
    }
  
    ListNode* swapPairs(ListNode* head) {
        if(!head){
          return head;
        }else if (!head->next){
          return head;
        }

        // ListNode* firstNode = new ListNode(head->val,head->next->next);
        // ListNode* secNode = new ListNode(head->next->val);
        // head = secNode;
        // head->next = firstNode;

        // same as the above 4 lines 
        head = new ListNode(head->next->val,new ListNode(head->val,head->next->next));

        head->next->next = swapPairs(head->next->next);
        return head;
    }



    
    ListNode* swapPairsTest2(ListNode* head) {
        ListNode* copy = head;
        int start = 0;
        while(copy){
          if(!copy->next){
            break;
          }

          ListNode* firstNode = new ListNode(copy->val,copy->next->next);
          ListNode* secNode = new ListNode(copy->next->val);
           
          copy = secNode;
          if(!start){  
            head = copy;
          } 
          copy->next = firstNode;

          cout<<"firstNode: "<<copy->val<<endl;
          cout<<"secNode: "<<copy->next->val<<endl;
          //cout<<"thirdNode: "<<copy->next->next->val<<endl;

          copy = copy->next->next;
          start++;
        }
        return head;
    }

    ListNode* swapPairsTest(ListNode* head) {
        for( auto node = head; node->next!=nullptr ; node = node->next->next){
          // ListNode* nextNode = node->next;
          // node->next = node->next->next;
          // nextNode->next = node;
          ListNode* firstNode = node;
          ListNode* secNode = node->next;
          ListNode* thirdNode = node->next->next;
          node = secNode;
          // node->next = firstNode;
          // node->next->next = thirdNode;
          
        }
        // ListNode* copy = head;
        // while(copy!=nullptr){
        //   ListNode* nextNode = copy->next;
        //   copy->next = copy->next->next;
        //   nextNode->next = copy;

        //   copy = copy -> next ->next;
        // }
        return head;
    }
};


int main(){

  ListNode* head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
 //head->next->next->next->next = new ListNode(5);
  Solution s;
  ListNode* test = s.swapPairs(head);
  while(test){
    cout<<test->val<<endl;
    test = test->next;
  }
  return 0;
}