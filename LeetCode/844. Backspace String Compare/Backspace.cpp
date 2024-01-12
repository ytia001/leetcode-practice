#include <string>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
      
      string dummyS , dummyT ;
      
      for(int i = 0 ; i < s.size() ; i++){
        if(s[i] == '#'){
          if(!dummyS.empty()) dummyS.pop_back();
        }else{
          dummyS.push_back(s[i]);
        }
      }

      for(int i = 0 ; i < t.size() ; i++){
        if(t[i] == '#'){
          if(!dummyT.empty()) dummyT.pop_back();
        }else{
          dummyT.push_back(t[i]);
        }
      }

      return dummyS == dummyT;
    }
};