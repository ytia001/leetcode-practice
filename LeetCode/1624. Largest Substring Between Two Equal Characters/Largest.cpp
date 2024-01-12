# include <string>
# include <vector>

using namespace std;

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
      int res = -1;
      vector<int> startFrom(26,-1);
      for(int i = 0 ; i < s.size() ; i++){
        if(startFrom[s[i]-'a'] == -1){
          startFrom[s[i]-'a'] = i;
        }
        else {
          res = max(res, i-startFrom[s[i]-'a']-1);
        }
      }
      return res;
    }
};