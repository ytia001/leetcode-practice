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
      if(q2.empty()){
        q2.push(x);
      } else{
        q1.push(q2.front());
        q2.pop();
        q2.push(x);
      }
    }
    
    int pop() {
      int returnVal = q2.front();
      q2.pop();
      int size = q1.size();
      if(!q1.empty()){
        int size = q1.size();
        while(--size>0){
          q1.push(q1.front());
          q1.pop();
        }
        q2.push(q1.front());
        q1.pop();
      }
      return returnVal;
    }
    
    int top() {
      return q2.front();
    }
    
    bool empty() {
      return q1.empty() && q2.empty();
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