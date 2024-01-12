#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool comparator (const string& a, const string& b){
      return a.size() > b.size();
    }

    int longestStrChain(vector<string>& words) {
      if(words.size() == 1) return 1;

      sort(words.begin(),words.end(),comparator);
      queue<pair<int,int>> q;

      int res = 1;

      for(int i = 0 ; i < words.size() ; i++){
        for(int j = 0 ; j < words[i].size() ; j++){
          string check = words[i].erase(j,1);
          auto next = find(words.begin(),words.end(),check);
          if(next != words.end()){
            q.push({next-words.begin(),res+1});
          }
        }
      }

      while(!q.empty()){
        auto [idx,count] = q.front();
        q.pop();
        res = max(res,count);
        for(int j = 0 ; j < words[idx].size() ; j++){
          string check = words[idx].erase(j,1);
          auto next = find(words.begin(),words.end(),check);
          if(next != words.end()){
            q.push({next-words.begin(),count+1});
          }
        }
      }

      return res;
    }
};