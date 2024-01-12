#include <string>
#include <unordered_set>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:

    int lengthOfLongestSubstring(string s) {
        int res = 0, curSize = 0 ;
        unordered_set<int> history;
        queue<int> q;
        for(int i = 0 ; i < s.size() ; i++){
          int current = s[i]-32;
          while(history.count(current)){
            history.erase(q.front());
            q.pop();
          }
          q.push(current);
          history.insert(current);
          curSize = q.size();
          res = max(res,curSize);
        }
        return res;
    }

    // int lengthOfLongestSubstring(string s) {
    //     int res = 0 ;
    //     int count = 0;
    //     //unordered_map<int,int> history;
    //     vector<int> history(100,0);
    //     for(int i = 0 ; i < s.size() ; i++){
    //       count = max(count + 1 - history[s[i]-32],(i+1)- history[s[i]-32]);
    //       history[s[i]-32] = count;
    //       res = max(res,count);
    //     }
    //     // for(int i = 0 ; i < s.size() ; i++){
    //     //   res = max(res,i+1-history[s[i]-32]);
    //     //   history[s[i]-32] = (i+1);
    //     // }
    //     res = max(res,count);
    //     return res;
    // }


    // int lengthOfLongestSubstring(string s) {
    //     int res = 0 ;
    //     int count = 0;
    //     unordered_set<int> history;
    //     for(int i = 0 ; i < s.size() ; i++){
    //       if(history.count(s[i]-32)){
    //         res = max(res,count);
    //         count = 0;
    //         history.clear();
    //       }
    //       history.insert(s[i]-32);
    //       count++;
    //     }
    //     res = max(res,count);
    //     return res;
    // }
};