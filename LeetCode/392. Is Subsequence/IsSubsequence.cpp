#include <string>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
      //int s_size = s.size();
      int s_ptr = 0 ;
      for(int i = 0 ; i < t.size() ; i++){
        if(s[s_ptr] == t[i]) s_ptr++;
      }

      return s_ptr == s.size();
    }
};