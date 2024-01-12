#include <vector>
#include <algorithm>

using namespace std;

class MyHashSet {
private:
    vector<int> hashSet;
public:
    MyHashSet() {
      
    }
    
    void add(int key) {
      int index = this->findIndex(key);
      if(index == -1){
        hashSet.push_back(key);
      }else if(hashSet[index] > key){
        hashSet.insert(hashSet.begin()+index,key);
      }else if(hashSet[index] < key){
        // if(index==hashSet.size()-1){
        //   hashSet.push_back(key);
        // }else{
        //   hashSet.insert(hashSet.begin()+index+1,key);
        // }
        hashSet.insert(hashSet.begin()+index+1,key);
      }else{
        return;
      }
    }
    
    void remove(int key) {
      if(this->contains(key)){
        int index = this->findIndex(key);
        hashSet.erase(hashSet.begin()+index);
      }
      return;
    }
    
    bool contains(int key) {
      int index = this->findIndex(key);
      if(index==-1){
        return false;
      }
      else if(hashSet[index]!=key){
        return false;
      }
      return true;
    }

    int findIndex(int key){
      if(hashSet.empty()) return -1;
      int l = 0;
      int r = hashSet.size()-1;
      while(l<r){
        int mid = l + (r-l)/2;
        if(hashSet[mid]>=key){
          r = mid;
        }else{
          l = mid+1;
        }
      }
      return l;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */