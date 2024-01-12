#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:

    bool wordBreak(string s, vector<string>& wordDict) {
      int size = s.size();
      stack<int> st;
      for(int i = 0 ; i < wordDict.size() ;i++){
        int next = s.find(wordDict[i]);
        if(next==0){
          st.push(next+wordDict[i].size());
        }
      }

      while(!st.empty()){
        int idx = st.top(); st.pop();
        if(idx>size) continue;
        if(idx==size) return true;
        for(int i = 0 ; i < wordDict.size() ;i++){
          int next = s.find(wordDict[i],idx);
          if(next==idx){
            st.push(next+wordDict[i].size());
          }
        }
      }

      return false;
    }


    // bool res = false;

    // void search(int start,string s, vector<string>& wordDict){
    //   if(start==s.size()) res = true;

    //   for(int i = 0 ; i < wordDict.size() ; i++){
    //     int next = s.find(wordDict[i],start);
    //     if(next==string::npos || next != start) continue;
    //     search(next+wordDict[i].size(),s,wordDict);
    //   }
    // }

    // bool wordBreak(string s, vector<string>& wordDict) {
    //   search(0,s,wordDict);
    //   return res;
    // }
};