#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
      //int sum = 0;
      //vector<int> startIdx(26,-1);
      vector<int> count(26,0);
      //vector<vector<string>> uniqueArray(s.size(),vector<string>(s.size(),""));
      vector<vector<int>> countArray(s.size(),vector<int>(s.size(),0));

      for(int j = 0 ; j < s.size() ; j++){
        unordered_set<char> uniqueChar;
        for(int i = j; i >= 0 ; i--){
          if(!uniqueChar.count(s[i])){
            countArray[i][j] = uniqueChar.size() + 1;
            uniqueChar.insert(s[i]);
          }else{
            if(s[i]==s[j] && j-i>1){
              count[s[i]-'a'] = countArray[i+1][j-1];
            }
            countArray[i][j] = countArray[i+1][j];
          }
        }
      }

      int res = 0;
      for(int i : count){
        res += i;
      }

      return res;
    }
};