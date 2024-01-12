#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:

    string minWindow(string s, string t) {
      if(t.size()>s.size()) return "";
      int res = INT_MAX;  
      int idx = -1;

      unordered_map<char,int> mp;
      for(int i  = 0; i < t.size() ; i++){
        mp[t[i]]++;
      }
      queue<int> q;
      int count = 0;

      for(int i = 0 ; i < s.size() ; i++){
        if(mp.count(s[i])){
          if(mp[s[i]]>0) count++;
          mp[s[i]]--;
          q.push(i);

          while(count==t.size() && mp[s[q.front()]]<0){
            mp[s[q.front()]]++;
            q.pop();
          }
        }
        
        if(count == t.size()){
          int curLength = q.back()-q.front()+1;
          if(curLength < res){
            res = curLength;
            idx = q.front();
          }
        }
      }

      if(idx==-1) return "";
      return s.substr(idx,res);
    }


    string minWindow(string s, string t) {
      if(t.size()>s.size()) return "";

      int res = INT_MAX;  
      int idx = -1;
      unordered_map<char,int> mp;
      for(int i  = 0; i < t.size() ; i++){
        mp[t[i]]++;
      }

      //queue<int> q;
      int l = 0;
      int count = 0;
      //int k = 0;
      for(int r = 0 ; r < s.size() ; r++){
        if(!mp.count(s[r])){
          if(count==0){
            l++;
            continue;
          }else{
            continue;
          }
        }else{
          mp[s[r]]--;
          count++;
          // if(mp[s[r]] > 0 && count != t.size()){
          //   continue;
          // }
          if(mp[s[r]] == 0 && count == t.size()){
            if(r-l+1< res){
              res = r-l+1;
              idx = l;
            } 
            while(l<=r){
              if(mp.count(s[l])){
                mp[s[l]]++;
                count--;
              }
              l++;
            }
          }
          else if(mp[s[r]] < 0){
            while(l<r){
              if(mp.count(s[l])){
                mp[s[l]]++;
                count--;
              }
              l++;
            }
          }
        }

      }
      if(idx==-1) return "";
      return s.substr(idx,res);
    }
};

//if(!mp.count(s[r])){
  //   if(!count){
  //     l++;
  //   }
  //   continue;
  // }else{
  //   mp[s[r]]--;
  //   count++;
  //   if(mp[s[r]]==0){
      
  //   }else{

  //   }
  // }