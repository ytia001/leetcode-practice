#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
      int l = 0;
      vector<int> res;
      unordered_map<char,int> mp;

      for(auto& ch : p){
        mp[ch]++;
      }

      int k = 0;
      int count = 0;

      for(int r = 0 ; r < s.size() ; r++){
        if(!mp.count(s[r])){
         count = 0;
         l = r + 1;
         continue;
        }
        if(mp[s[r]]<=0){
          while(mp[s[r]]<=0){
            mp[s[l]]++;
            count--;
            l++;
          }
        }

        mp[s[r]]--;
        count++;
        if(count==p.size()){
          res.push_back(l);
        }
      }

      // for(int r = 0 ; r < s.size() ; r++){
      //   if(!mp.count(s[r]) || mp[s[r]]<=0){
      //     k++;
      //     while(k>0){
      //       if(!mp.count(s[l])){
      //         k--;
      //       }
      //       else if(mp[s[l]]<=0){
      //         mp[s[l]]++;
      //         k--;
      //       }
      //       l++;
      //     }
      //   }else{
      //     mp[s[r]]--;
      //     count++;
      //     if(count==p.size()){
      //       //count = 0;
      //       res.push_back(l);
      //       //l = r + 1;
      //     }
      //   }
      // }

      return res;
    }
};