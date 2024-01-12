#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <queue>

using namespace std;

class MinStack {
private:
    vector<int> vect;
    //stack<int> maxSt;
    //map<int,queue<int>> indexMap;
    // int currentIdx;
    map<int,int> intMap;
    int size;
public:
    MinStack() {
      // currentIdx = 0;
      size = 0;
    }
    
    void push(int val) {
      vect.push_back(val);
      size++;
      //indexMap[val].push(currentIdx++);
      intMap[val]++;
    }
    
    void pop() {
      // indexMap[vect[vect.size()-1]].pop();
      // if(indexMap[vect[vect.size()-1]].empty()){
      //   indexMap.erase(vect[vect.size()-1]);
      // }
      intMap[vect[--size]]--;
      if(intMap[vect[size]]==0){
        intMap.erase(vect[size]);
      }
      vect.pop_back();
    }
    
    int top() {
      return vect[size-1]; 
    }
    
    int getMin() {
      auto endIt = intMap.begin();
      return endIt->first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */