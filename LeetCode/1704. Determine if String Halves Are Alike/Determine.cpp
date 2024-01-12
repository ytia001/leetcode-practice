# include <string>
# include <vector>
# include <unordered_map>

using namespace std;

class Solution {
public:
    bool check(char& c){
      if(c == 'a' || c == 'A') return true;
      else if( c == 'e' || c == 'E') return true;
      else if( c == 'i' || c == 'I') return true;
      else if( c == 'o' || c == 'O') return true;
      else if( c == 'u' || c == 'U') return true;
      return false;
    }

    bool halvesAreAlike(string s) {
      int count = 0 , indicator = s.size()/2;

      for(int i = 0 ; i < s.size() ; i++){
        if(check(s[i])){
          if(i < indicator){
            count++;
          }
          else{
            count--;
          }
        }
      }
      
      return count == 0;
    }
};