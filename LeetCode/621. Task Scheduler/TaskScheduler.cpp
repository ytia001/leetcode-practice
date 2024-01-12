#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:

    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> m;
        int count = tasks.size();
        int res = 0;
        for(auto c : tasks){
          m[c]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,less<>> pq1;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq2;

        for(auto i : m){
          pq1.push({i.second,i.first});
        }

        while(count>0){
          ++res;
          //if(!pq2.empty() && pq2.top().first<=res)
          if(!pq1.empty() && !pq2.empty()){
            if(pq1.top().first >= m[pq2.top().second]){
              auto top = pq1.top();
              pq1.pop();
              count--;
              if(--m[top.second]!=0){
                pq2.push({res+1+n,top.second});
              }
            }
          } 

          else if(!pq2.empty() && pq2.top().first==res){
            auto top = pq2.top();
            pq2.pop();
            count--;
            if(--m[top.second]!=0){
              pq2.push({res+1+n,top.second});
            }
          }

          else if(!pq1.empty()){
            auto top = pq1.top();
            pq1.pop();
            count--;
            if(--m[top.second]!=0){
              pq2.push({res+1+n,top.second});
            }
          }
        }

        return res;
    }

    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> m;
        int count = tasks.size();
        int res = 1;
        for(auto c : tasks){
          m[c]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,less<>> pq1;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq2;

        for(auto i : m){
          pq1.push({i.second,i.first});
        }

        while(count>0){
          //if(!pq2.empty() && pq2.top().first<=res)
          if(!pq2.empty() && pq2.top().first==res){
            auto top = pq2.top();
            pq2.pop();
            count--;
            //  if(--m[top.second]==0){
            //   continue;
            //  }else{
            //   pq2.push({top.first+1+n,top.second});
            //  }
            if(--m[top.second]!=0){
              pq2.push({res+1+n,top.second});
            }
            res++;
          }

          if(!pq1.empty()){
            auto top = pq1.top();
            pq1.pop();
            count--;
            // if(--m[top.second]==0){
            // continue;
            // }else{
            //   pq2.push({res+1+n,top.second});
            // }
            if(--m[top.second]!=0){
              pq2.push({res+1+n,top.second});
            }
          }

          res++;
        }

        return res;
    }
};