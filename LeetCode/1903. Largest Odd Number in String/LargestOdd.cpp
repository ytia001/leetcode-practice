# include <string>

using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
      int idx = -1;
      for(int i = num.size()-1 ; i >= 0 ; i--){
        if((num[i]-'0')%2){
          idx = i;
          break;
        }
      }

      return idx == -1 ? "" : num.substr(0,idx+1);
    }
};