#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
      string res = "";
      int size = s.size();

      for( int l=0 ;l<size ; l++){
        int r = size-1;
        while(l<r){
          if(s[l]==s[r]){
            
          }else{
            r--;
          }
        }
      }
    }
};