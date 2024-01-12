#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:

    int Answer(vector<int>& g, vector<int>& s) {
       sort(g.begin(),g.end());
       sort(s.begin(),s.end());
       int i = 0;
       for(int j = 0 ; i<g.size() && s.size() ; i++){
        if(g[i]<=s[j]) i++;
       }
       return i;
    }

    int findContentChildren(vector<int>& g, vector<int>& s) {
        int res = 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int ptr1 = 0, ptr2 = 0;
        while(ptr1<g.size() && ptr2<s.size()){
          if(g[ptr1]<=s[ptr2]){
            res++;
            ptr1++;
            ptr2++;
          }else{
            ptr2++;
          }
        }
        return res;
    }

    int findContentChildrenTest(vector<int>& g, vector<int>& s) {
        int res = 0;
        sort(g.begin(),g.end());
        priority_queue<int,vector<int>,greater<>> pq(s.begin(),s.end());
        for(int i : g){
          while(!pq.empty()){
            if(i<=pq.top()){
              res++;
              pq.pop();
              break;
            }else{
              pq.pop();
            }
          }
        }
        return res;
    }
};