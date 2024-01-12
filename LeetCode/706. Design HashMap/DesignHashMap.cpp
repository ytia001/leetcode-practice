#include <deque>
#include <vector>
#include <queue>
#include <unordered_set>
#include <set>

using namespace std;


class MyHashMap {
public:
    //priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    unordered_set<int> keySet;
    vector<pair<int,int>> hashMap;

    MyHashMap() {
        
    }
    
    void put(int key, int value) {
      if(keySet.count(key)){
        for(int i = 0 ; i < hashMap.size() ; i++){
          if(hashMap[i].first == key){
            hashMap[i].second = value;
          }
        }
      }else{
        keySet.insert(key);
        hashMap.push_back({key,value});
      }
    }
    
    int get(int key) {
      if(!keySet.count(key)) return -1;

      for(int i = 0 ; i < hashMap.size() ; i++){
        if(hashMap[i].first == key){
          return hashMap[i].second;
        }
      }
      
      return -1;
    }
    
    void remove(int key) {
      if(keySet.count(key)){
        for(int i = 0 ; i < hashMap.size() ; i++){
          if(hashMap[i].first == key){
            hashMap.erase(hashMap.begin()+i);
            break;
          }
        }
        keySet.erase(key);
      }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */