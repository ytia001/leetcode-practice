#include <queue>
#include <vector>
#include <map>
#include <stack>

using namespace std;

class Solution {
public:

    vector<int> dailyTemperatures(vector<int>& temperatures) {
      int size = temperatures.size();
      vector<int> res(temperatures.size(),0);
      stack<pair<int,int>> q;
      q.push({temperatures[size-1],size-1});

      for(int i = size - 2 ; i >= 0 ; i--){
        if(temperatures[i] < temperatures[i+1]){
          res[i] = 1;
        }else{
          stack<pair<int,int>> dummy = q;
          while(!dummy.empty()){
            auto front = dummy.top();
            dummy.pop();
            if(temperatures[i] < front.first){
              res[i] = front.second - i;
              break;
            }
          }
        }
        q.push({temperatures[i],i});
      }

      return res;
    }

    vector<int> dailyTemperatures(vector<int>& temperatures) {
      int size = temperatures.size();
      vector<int> res(temperatures.size(),0);
      map<int,int> mp;
      mp[temperatures[size-1]] = size-1;

      for(int i = size - 2 ; i >= 0 ; i--){
        if(temperatures[i] < temperatures[i+1]){
          res[i] = 1;
        }else{
          auto front = mp.upper_bound(temperatures[i]);
          if(front!=mp.end()){
            res[i] = front->second - i;
          }
        }
        mp[temperatures[i]] = i;
      }

      return res;
    }

    vector<int> dailyTemperatures(vector<int>& temperatures) {
      queue<int> q;
      vector<int> res(temperatures.size(),0);
      for(int i = 0 ; i < temperatures.size()-1 ; i++){
        if(temperatures[i] < temperatures[i+1]){
          res[i] = 1;
        }else{
          q.push(i);
        }

        int size = q.size();
        while(size-->0){
          int idx = q.front();
          q.pop();
          res[idx]++;
          if(temperatures[idx] >= temperatures[i+1]){
            // res[idx]++;
            q.push(idx);
          }
        }
      }

      while(!q.empty()){
        res[q.front()] = 0;
        q.pop();
      }

      return res;
    }
};