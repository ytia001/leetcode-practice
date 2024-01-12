#include <string>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:

    string decodeAtIndex(string s, int k) {
      string toHold;
      int current = 0;
      stack<string> st;
      stack<int> counter;
      for(int i = 0 ; i < s.size() ; i++){
        if(isalpha(s[i])){
          toHold += s[i];
        }else{
          
        }
      }

      return string(1,toHold[k]);
    }

    // string decodeAtIndex(string s, int k) {
    //   string toHold;
    //   for(int i = 0 ; i < s.size() ; i++){
    //     if(isalpha(s[i])){
    //       toHold += s[i];
    //     }else{
    //       if(s.size() >= k) break;
    //       string dummy = toHold;
    //       for(int i = 0 ; i < s[i]-'0' ; i++){
    //         dummy += dummy;
    //       }
    //       toHold = dummy;
    //     }
    //   }

    //   return string(1,toHold[k]);
    // }
};