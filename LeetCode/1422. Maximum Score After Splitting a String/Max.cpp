# include <string>

using namespace std;

class Solution {
public:
    int maxScore(string s) {
      int res = 0;
      int zero = 0 , one = 0 ;
      for(int i = 0 ; i < s.size() ; i++){
        if( s[i] == '1' ){
          one++;
        }
      }

      for(int i = 0 ; i < s.size() ; i++){
        if(s[i] == '0'){
          zero++;
        }else{
          one--;
        }
        res = max(res,zero+one);
      }
      return res;
    }
};