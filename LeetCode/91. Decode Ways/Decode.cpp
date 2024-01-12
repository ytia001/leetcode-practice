# include <string>
# include <unordered_map>

using namespace std;

class Solution {
public:
    int charToNum(char c){
      return c-'0';
    }

    int numDecodings(string s) {
      vector<int> dp (s.size() , 0);
      dp[0] = charToNum(s[0]) > 0 ? 1 : 0;

      if(s.size() > 1){
        if(!dp[0]){
            dp[1] = dp[0];
        }else{
            dp[1] = charToNum(s[1]) > 0 ?  1 : 0;
            int twoDigit = (charToNum(s[0]))*10 + charToNum(s[1]);
            dp[1] = (twoDigit > 0 && twoDigit < 27) ? dp[1] + 1 : dp[1];
        }
      }

      for(int i = 2 ; i < s.size() ; i++){
        if(charToNum(s[i])){
          dp[i] += dp[i-1];
          int twoDigit = (charToNum(s[i-1]))*10 + charToNum(s[i]) ;
          if(charToNum(s[i-1]) && twoDigit > 0 && twoDigit < 27){
            dp[i] += dp[i-2];
          }
        }else{
          int twoDigit = (charToNum(s[i-1]))*10 + charToNum(s[i]) ;
          if(twoDigit > 0 && twoDigit < 27){
            dp[i] += dp[i-2];
          }  
        }
        if(!dp[i-1] && !dp[i]) return 0;
      }

      return dp[s.size()-1];
    }

    int numDecodings(string s) {
      return start(0,s);  
    }

    int start(int index , string& s){
      if(s[index] == '0'){
        return 0;
      }
      else if(index >= s.size()-1){
        return 1;
      }
      int twoDigit = (s[index]-'0')*10 + (s[index+1]-'0');

      int first = start(index+1,s);
      int second = (twoDigit > 0 && twoDigit < 27) ? start(index+2,s) : 0;

      return first+second;
    }
};