#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
      if(digits.empty()) return {};
      int ch = 0;
      unordered_map<int,vector<string>> mp;
      for(int i = 2 ; i <= 9 ; i++){
        if(i==7 || i==9){
          for(int j = 0 ; j < 4 ; j++){
            mp[i].push_back(string(1,'a'+ch));
            ch++;
          }
        }else{
          for(int j = 0 ; j < 3 ; j++){
            mp[i].push_back(string(1,'a'+ch));
            ch++;
          }
        }
      }

      vector<string> res = {{}};
      for(int i = 0 ; i < digits.size() ; i++){
        vector<string> current = res;
        res.clear();
        for(auto nextStr : mp[digits[i]-48]){
          for(string s : current){
            string newStr = s + nextStr;
            res.push_back(newStr);
          }
        }
      }
      return res;
    }
};