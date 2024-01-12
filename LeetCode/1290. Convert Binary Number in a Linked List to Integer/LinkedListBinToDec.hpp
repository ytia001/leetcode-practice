#include<vector>
#include<iostream>
#include<cmath>
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
    int getDecimalValue(ListNode* head);
    void binToDec(ListNode* head,std::vector<int>& binVect);
    int getDecimalValueSoln(ListNode* head);
};