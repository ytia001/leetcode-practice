#include <vector>

using namespace std;

class CustomStack {
public:
    vector<int> stack;
    int idx = 0;

    CustomStack(int maxSize) {
      stack.resize(maxSize);
    }
    
    void push(int x) {
      if(idx < stack.size()){
        stack[idx] = x;
        idx++;
      }
    }
    
    int pop() {
      int val = stack[idx];
      idx--;
      return val;
    }
    
    void increment(int k, int val) {
      if( k <= stack.size()){
        if( k <= idx){
          for(int i = 0 ; i < k ; i++){
            stack[i] += val;
          }
        }else{
          for(int i = 0 ; i < idx ; i++){
            stack[i] += val;
          }
        }
      }else{
        for(int i = 0 ; i < stack.size() ; i++){
          stack[i] += val;
        }
      }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */