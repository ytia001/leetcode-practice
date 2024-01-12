#include <queue>

using namespace std;

class MyStack {
private:  
    queue<int> q1;
    queue<int> q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
      if(q1.empty() && q2.empty()){
        q2.push(x);
      }
      else if(q2.size()==1){
        q1.push(q2.front());
        q2.pop();
        q2.push(x);
      }else{
        q2.push(q1.front());
        q1.pop();
        q1.push(x);
      }
    }
    
    int pop() {
      int returnVal;
      if(q2.size()==1){
        returnVal = q2.front();
        q2.pop();
        int removeSize = q1.size();
        while( --removeSize > 0){
          q2.push(q1.front());
          q1.pop();
        }
      }else{
         returnVal = q1.front();
        q1.pop();
        int removeSize = q2.size();
        while( --removeSize > 0){
          q1.push(q2.front());
          q2.pop();
        }
      }
      return returnVal;
    }
    
    int top() {
      if(q2.size()==1){
        return q1.front();
      }else{
        return q2.front();
      }
    }
    
    bool empty() {
      return (q1.empty() && q2.empty());
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */