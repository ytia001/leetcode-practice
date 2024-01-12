#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:

    int change ( char c ){
      if(c == 'I') return 1;
      if(c == 'V') return 5;
      if(c == 'X') return 10;
      if(c == 'L') return 50;
      if(c == 'C') return 100;
      if(c == 'D') return 500;
      if(c == 'M') return 1000;
      return -1;
    }


    int romanToInt(string s) {
      //unordered_map<char,int> mp = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
      int res = 0;
      int prev = change(s[0]);

      for(int i = 1 ; i < s.size() ; i++){
        if(prev == -1){
          prev = change(s[i]);
        }else{
          if(change(s[i]) > prev){
            res += change(s[i])-prev;
            prev = -1;
          }else{
            res += prev;
            prev = change(s[i]);
          }
        }
      }

      if(prev != -1) res += prev;
      return res; 
    }


    int romanToInt(string s) {
      unordered_map<char,int> mp = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
      int res = 0;
      int prev = mp[s[0]];

      for(int i = 1 ; i < s.size() ; i++){
        if(prev == NULL){
          prev = mp[s[i]];
        }else{
          if(mp[s[i]] > prev){
            res += mp[s[i]]-prev;
            prev = NULL;
          }else{
            res += prev;
            prev = mp[s[i]];
          }
        }
      }

      if(prev != NULL) res += prev;
      return res;
    }
};