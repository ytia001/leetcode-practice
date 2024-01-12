#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
      stack<int> st;
      for(int i = 0 ; i < tokens.size() ; i++ ){
        if(tokens[i]=="+" || tokens[i]=="-" || tokens[i] == "*" || tokens[i] == "/"){
          int right = st.top();
          st.pop();
          int left = st.top();
          st.pop();
          int curRes;
          if(tokens[i]=="+") curRes = left + right;
          if(tokens[i]=="-") curRes = left - right;
          if(tokens[i]=="*") curRes = left * right;
          if(tokens[i]=="/") curRes = left / right;
          st.push(curRes);
        }else{
          st.push(stoi(tokens[i]));
        }
      }  
      return st.top();
    }
};