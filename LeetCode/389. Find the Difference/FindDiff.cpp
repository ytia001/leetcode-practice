#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
      vector<int> charVect(26,0);
      int s_size = s.size() , t_size = t.size();
      // if(t_size > s_size + 1) return 

      for(int i = 0 ; i < t.size() ; i++){
        if(i == t.size() -1 ){
          charVect[t[i] - 'a']++;
          continue;
        }

        charVect[s[i] - 'a']--;
        charVect[t[i] - 'a']++;
      }

      for(int i  = 0 ; i < charVect.size() ; i++){
        if(charVect[i]) return 'a' + i;
      }

      return 'a';
    }
};