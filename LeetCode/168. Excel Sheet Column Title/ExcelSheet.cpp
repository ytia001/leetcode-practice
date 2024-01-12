#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:

    

    string convertToTitle(int columnNumber) {
      string res;
      vector<char> ch(27);
      for(int i = 1 ; i<=26 ; i++){
        ch[i] = 'A' + i - 1;
      }
      int remainder = INT_MAX;
      int left = columnNumber;
    
      while(left > 26){
        remainder = left%26;
        left = left/26;
        if(remainder == 0){
          left--;
          remainder = 26;
        }
        //cout<<"left: "<<left<<" remainder: "<<remainder<<endl;
        res = (remainder == 0 ? 'Z' : ch[remainder]) + res;
      }

      res = ch[left] + res;

      return res;
    }

    string convertToTitle(int columnNumber) {
      string res;
      //unordered_map<char,int> mp;
      vector<char> ch(26);
      for(int i = 1 ; i<=26 ; i++){
        ch[i] = 'A' + i - 1;
      }
      // for(char ch = 'A' ; ch <= 'Z' ; ch++ ){
      //   mp[ch] = ch - 'A' + 1;
      // }
      int remainder = INT_MAX;
      int left = columnNumber;

      while(left > 1){
        remainder = left%26;
        left = left/26;
        res = ch[remainder] + res;
      }

      return res;
    }
};