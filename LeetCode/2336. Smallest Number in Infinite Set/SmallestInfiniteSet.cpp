#include <set>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Answer {
public:
    int cur = 1;
    set<int> added; 
    int popSmallest() {
        if (!added.empty()) {
            int res = *begin(added);
            added.erase(begin(added));
            return res;
        }
        return cur++;
    }
    void addBack(int num) {
        if (num < cur)
            added.insert(num);
    }
};

class SmallestInfiniteSet {
 private:
    //vector<int> container;
    set<int> container;

 public:
    SmallestInfiniteSet() {
        for(int i = 1 ; i<=1000 ; i++){
          container.insert(i);
        }
    }
    
    int popSmallest() {
        auto it = container.begin();
        int smallest = *it;
        container.erase(smallest);
        return smallest;
    }
    
    void addBack(int num) {
        if(container.count(num)!=1){
          container.insert(num);
        }
    }


    // TEST 1
    // SmallestInfiniteSet():container(1001,1){
        
    // }
    
    // int popSmallest() {
    //     for(int i = 1; i < container.size() ; i++){
    //       if(container[i]){
    //         container[i] = 0;
    //         return i;
    //       }
    //     }
    //     return -1;
    // }
    
    // void addBack(int num) {
    //     if(container[num]==0){
    //       container[num]=1;
    //     }
    // }

    // TEST 2
    // SmallestInfiniteSet(){
    //     for(int i = 1 ; i<=1000 ; i++){
    //       container.insert(i);
    //     }
    // }
    
    // int popSmallest() {
    //     auto it = container.begin();
    //     int smallest = *it;
    //     container.erase(smallest);
    //     return smallest;
    // }
    
    // void addBack(int num) {
    //     if(container.count(num)!=1){
    //       container.insert(num);
    //     }
    // }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */