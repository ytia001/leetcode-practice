#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

class ListNode{
  int val;
  ListNode* next;
  ListNode(int input): val(input), next(nullptr){};
};

class LRUCache {
public:

    ListNode* start;
    ListNode* end;
    int size;
    unordered_map<int,pair<ListNode*,ListNode*>> keyToLnode;

    LRUCache(int capacity) {
      size = capacity;
      start = nullptr;
      end = nullptr;
    }
    
    int get(int key) {
        
    }
    
    void put(int key, int value) {
      if(keyToLnode.count(key)){
        ListNode* prevNode= keyToLnode[key].first;
        ListNode* curNode= keyToLnode[key].second;
        prevNode ->next = curNode->next;

      }else{

      }
    }
};

// class LRUCache {
// public:
//     int newID = 0;
//     unordered_map<int,int> keyToIndex;
//     unordered_map<int,int> IndextoVal;
//     priority_queue<int,vector<int>,greater<>> pq;
//     vector<pair<int,int>> vect;

//     LRUCache(int capacity) {
//       vector<pair<int,int>> dummy(capacity,{-1,-1});
//       vect = dummy;
//     }
    
//     int get(int key) {
//       newID++;
//       int returnVal;
//       if(keyToIndex.count(key)){
//         int curIdx = keyToIndex[key];
//         returnVal = vect[curIdx];


//       }else{
//         return -1;
//       }

//       return returnVal;
//     }
    
//     void put(int key, int value) {
//       newID++;
//       if(keyToIndex.count(key)){
//         int curIdx = keyToIndex[key];
        


//       }else{
//         if(newID%(vect.size())==-1){
//           vect[newID] = {key,value};
//           keyToIndex[key] = newID;
//         }else{
//           int toDeleteKey = vect[newID].first;
//           keyToIndex.erase(toDeleteKey);
//           vect[newID] = {key,value};
//           keyToIndex[key] = newID;
//         }
//       }
//     }
// };

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */