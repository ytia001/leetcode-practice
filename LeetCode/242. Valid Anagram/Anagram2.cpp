# include <string>
# include <vector>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
      if(s.size() != t.size()) return false;
      vector<int> alpha(26,0);
      for(auto& str : s){
        alpha[str -'a']++;
      }  
      for(auto& str : t){
        if(--alpha[str-'a'] < 0){
          return false;
        }
      }

      return true;
    }
};