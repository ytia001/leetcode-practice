#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
      vector<vector<int>> palidrome(s.size(),vector<int>(s.size(),0));
      int startPos = 0 , length = 1;

      for(int i = 0 ; i < s.size() ; i++){
        palidrome[i][i] = 1;
      }

      for(int end = 0 ; end < s.size() ; end++){
        for(int start = end - 1 ; start >= 0 ; start --){
          int currentLength = end - start + 1;
          if(currentLength == 2 && s[start]==s[end]){
            palidrome[start][end] = 1;
            if(currentLength > length){
              startPos = start;
              length = currentLength;
            }
          }

          else if ( s[start] == s[end] && palidrome[start+1][end-1]){
            palidrome[start][end] = 1;
            if(currentLength > length){
              startPos = start;
              length = currentLength;
            }
          }
        }
      }

      return s.substr(startPos,length);
    }
};