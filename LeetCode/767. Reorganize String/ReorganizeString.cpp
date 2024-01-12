#include <string>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:

    string reorganizeString(string s) {
      string res;
      priority_queue<pair<int,char>,vector<pair<int,char>>,less<>> pq;
      unordered_map<char,int> charMap;
      for(char c : s){
        charMap[c]++;
      }
      for(auto i : charMap){
        pq.push({i.second,i.first});
      }
      
      vector<pair<int,char>> dummy;
      while(!pq.empty()){
        auto next = pq.top();
        pq.pop();
        if(res.empty() || res.back()!=next.second){
          res += next.second;
          if(next.first>1) pq.push({next.first-1,next.second});
        }
        else{
          if(pq.empty()) return "";
          dummy.push_back(next);
          continue;
        }

        while(!dummy.empty()){
          pq.push(dummy.back());
          dummy.pop_back();
        }
      }

      return res;
    }


     string reorganizeString(string s) {
      string res;
      priority_queue<pair<int,char>,vector<pair<int,char>>,less<>> pq;
      unordered_map<char,int> charMap;
      for(char c : s){
        charMap[c]++;
      }
      for(auto i : charMap){
        pq.push({i.second,i.first});
      }
      
      vector<pair<int,char>> dummy;
      while(!pq.empty()){
        auto next = pq.top();
        pq.pop();
        // cout<<"next.first: "<<next.first<<" next.second: "<<next.second<<endl;
        // cout<<"res: "<<res<<endl;
        if(res.empty()){
          res += next.second;
          if(next.first>1) pq.push({next.first-1,next.second});
        }
        else if(res.back()!=next.second){
          res += next.second;
          if(next.first>1) pq.push({next.first-1,next.second});
        }
        else{
          if(pq.empty()) return "";
          dummy.push_back(next);
          continue;
        }

        while(!dummy.empty()){
          pq.push(dummy.back());
          dummy.pop_back();
        }
      }

      return res;
    }

    string reorganizeString(string s) {
      string res;
      char prev = '0';
      unordered_map<char,int> charMap;
      for(char c : s){
        charMap[c]++;
      }

      while(!charMap.empty()){
        bool added = false;
        for(auto pair : charMap){
          if(pair.second !=0 && prev == '0'){
            prev = pair.first;
            res += pair.first;
            if(--charMap[pair.first] == 0 ) charMap.erase(pair.first);
            added = true;
          }
          if(pair.second !=0  && prev != pair.first){
            prev = pair.first;
            res += pair.first;
            if(--charMap[pair.first] == 0 ) charMap.erase(pair.first);
            added = true;
          }
        }
        if(!added) return "";
      }

      return res;
    }


    string reorganizeString(string s) {
      string res;
      int prev = -1;
      vector<int> countVect(26,0);
      for(char c : s){
        countVect[c-'a']++;
      }

      while(!countVect.empty()){
        bool added = false;
        for(int i = 0 ; i < countVect.size() ; i++){
          if(countVect[i]!=0 && prev == -1){
            prev = i;
            res += 'a' + i;
            countVect[i]--;
            added = true;
          }
          if(countVect[i]!=0 && prev != i){
            prev = i;
            res += 'a' + i;
            countVect[i]--;
            added = true;
          }
          // if(countVect[i]!=0 && prev != i){
          //   prev = i;
          //   res += 'a' + i;
          //   countVect[i]--;
          //   added = true;
          // }
        }
        if(!added) return "";
      }

      return res;
    }
};