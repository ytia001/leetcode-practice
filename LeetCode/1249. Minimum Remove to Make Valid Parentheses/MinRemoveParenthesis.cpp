#include <string>
#include <stack>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:

    // string minRemoveToMakeValidTest2(string s) {
    //     int overall = 0;
    //     vector<int> idx;
    //     for(int i = 0 ; i<s.size() ; i++){
    //       if(s[i]=='('){
    //         overall--;
    //         idx.push_back(i);
    //       }
    //       if(s[i]==')'){
    //         overall++;
    //         if(overall>0) idx.push_back(i);
    //       }
    //     }

    //     while(!idxToRemove.empty()){
    //       int idx = idxToRemove.top();
    //       idxToRemove.pop();
    //       copy.erase(idx,1);
    //     }

    //     return copy;
    // }

    // string minRemoveToMakeValidTest(string s) {
    //     string copy = "";
    //     stack<int> idxToRemove;
    //     for(int i = 0 ; i<s.size() ; i++){
    //       if(s[i]=='('){
    //         idxToRemove.push(i);
    //       }
    //       if(s[i]==')'){
    //         if(idxToRemove.empty()){
    //           copy.erase(i,1);
    //           continue;
    //         }
    //         idxToRemove.pop();
    //       }
    //     }

    //     while(!idxToRemove.empty()){
    //       int idx = idxToRemove.top();
    //       idxToRemove.pop();
    //       copy.erase(idx,1);
    //     }

    //     return copy;
    // }



    string minRemoveToMakeValid(string s) {
        stack<int> idxToRemove;
        for(int i = 0 ; i<s.size() ; i++){
          if(s[i]=='('){
            idxToRemove.push(i);
          }
          if(s[i]==')'){
            if(!idxToRemove.empty() && s[idxToRemove.top()]=='('){
              idxToRemove.pop();
            }
            else{
              idxToRemove.push(i);
            }
          }
        }

        if(idxToRemove.empty()) return s;

        while(!idxToRemove.empty()){
          int idx = idxToRemove.top();
          idxToRemove.pop();
          s.erase(idx,1);
        }

        return s;
    }

    string minRemoveToMakeValidTest3(string s) {
        stack<int> idxToRemove;
        for(int i = 0 ; i<s.size() ; i++){
          if(s[i]=='('){
            idxToRemove.push(i);
          }
          if(s[i]==')'){         
            if(!idxToRemove.empty() && s[idxToRemove.top()]=='('){
              idxToRemove.pop();
              continue;
            }
            idxToRemove.push(i);
          }
        }

        while(!idxToRemove.empty()){
          int idx = idxToRemove.top();
          idxToRemove.pop();
          s.erase(idx,1);
        }

        return s;
    }
};

int main(){
  Solution s;
  string test = "))((";
  cout<<s.minRemoveToMakeValidTest3(test)<<endl;
  return 0;
}