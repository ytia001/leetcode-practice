#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    bool wordBreak(string s, vector<string>& wordDict) {
      string dummy = " "+ s;
      int size = dummy.size();
      vector<bool> res(size,false);
      res[0] = true;

      for(int i = 1 ; i < size ; i++){
        for(int j = i-1 ; j >=0 ; j--){
          if(res[j] == true){
            res[i] = res[i] | find(wordDict.begin(),wordDict.end(),s.substr(j+1,i-j))!=wordDict.end();
          }
        }
      }

      return res[size];
    }

    bool wordBreak(string s, vector<string>& wordDict) {
      int size = s.size();
      vector<bool> res(size+1,false);
      res[0] = true;

      for(int i = 0 ; i < size ; i++){
        for(int j = i ; j >=0 ; j--){
          if(res[j] == true){
            bool check = find(wordDict.begin(),wordDict.end(),s.substr(j,i-j+1))!=wordDict.end() ? true : false;
            res[i+1] = res[i+1] | check;
          }
        }
      }

      return res[size];
    }
};