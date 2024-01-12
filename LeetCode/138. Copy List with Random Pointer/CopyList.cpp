#include <unordered_map>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
      if(!head) return nullptr;

      unordered_map<Node*,Node*> oldToNew;
      Node* ptr = head;
      Node* newHead = new Node(0);
      Node* newPtr = newHead;

      while(ptr){
        oldToNew[ptr] = newPtr;
        newPtr->val = ptr->val;
        if(!oldToNew.count(ptr->random)){
          if(ptr->random){
            Node* newNode  = new Node(0);
            newPtr->random = newNode;
            oldToNew[ptr->random] = newNode;
          }else{
            newPtr->random = nullptr;
            oldToNew[nullptr] = nullptr;
          }
        }else{
          newPtr ->random = oldToNew[ptr->random];
        }
        if(!oldToNew.count(ptr->next)){
          if(ptr->next){
            Node* newNode  = new Node(0);
            newPtr->next = newNode;
            oldToNew[ptr->next] = newNode;
          }else{
            newPtr->next = nullptr;
            oldToNew[nullptr] = nullptr;
          }
        }else{
          newPtr ->next = oldToNew[ptr->next];
        }
        // if(!oldToNew.count(ptr)) oldToNew[ptr] = newPtr;
        ptr = ptr ->next;
        newPtr = newPtr ->next;
      }

      return newHead; 
    }
};