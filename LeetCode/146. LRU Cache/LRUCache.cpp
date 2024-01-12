#include <deque>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class LRUCache {
private:
    int maxSize;
    unordered_set<int> st;
    unordered_map<int,int> mp;
    deque<int> dq;
public:
    LRUCache(int capacity){
      maxSize = capacity;
    }
    
    int get(int key) {
      if(st.count(key)){
        
        return mp[key];
      }else{
        return -1;
      }
    }
    
    void put(int key, int value) {
      
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */