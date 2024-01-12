#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        s.push(-1);
        int m = pushed.size(); 
        int idx = 0;
        int topVal = 0;
        for(int i : popped){      // use top value of stack or current val in pushed vector to satisfy the current value at popped vector

          while( idx <m ){
            if(pushed[idx]==i){
              break;
            }
            topVal = s.top();
            if(topVal==i){
              //cout<<"3"<<endl;
              s.pop();
              break;
            }
            //cout<<"1"<<endl;
            s.push(pushed[idx++]);
          }

          if(idx >= m ){
            //cout<<"2"<<endl;
            topVal = s.top();
            s.pop();
            if(topVal!=i){
              return false;
            }
          }else{
            if(topVal==i){
              continue;
            }
            idx++;
          }
          
        }
        return true;
    }

    // bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    //     stack<int> s;
    //     int m = pushed.size(); 
    //     int idx = 0;
    //     int topVal = 0;
    //     for(int i : popped){      // use top value of stack or current val in pushed to satisfy the value at popped

    //       while( idx <m && pushed[idx]!=i){
    //         topVal = s.top();
    //         if(topVal==i){
    //           cout<<"3"<<endl;
    //           s.pop();
    //           break;
    //         }
    //         cout<<"1"<<endl;
    //         s.push(pushed[idx++]);
    //       }

    //       if(idx >= m ){
    //         cout<<"2"<<endl;
    //         topVal = s.top();
    //         s.pop();
    //         if(topVal!=i){
    //           return false;
    //         }
    //       }else{
    //         if(topVal==i){
    //           continue;
    //         }
    //         idx++;
    //       }
          
    //     }
    //     return true;
    // }
};

int main(){
  Solution s;
  vector<int> pushed = {1,2,3,4,5,6,7};
  vector<int> popped = {1,2,5,3,6,7,4};
  //cout<<s.validateStackSequences(pushed,popped)<<endl;
  //cout<<s.validateStackSequencesTest(pushed,popped)<<endl;
  return 0;
}