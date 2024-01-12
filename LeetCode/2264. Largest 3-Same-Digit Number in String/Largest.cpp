# include <string>

using namespace std;

class Solution {
public:
    string largestGoodInteger(string num) {
      string res = "";

      for(int i = 0 ; i < num.size() - 3 ; i++){
        string check = num.substr(i,3);
        if(isGood(check)) {
          if(res.empty() || check[0] > res[0]){
            res = check;
          }
        }
      }  
      return res;
    }

    bool isGood(string& s){
      return s[0]==s[1] && s[1]==s[2];
    }
};