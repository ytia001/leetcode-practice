#include <string>

using namespace std;

class Solution {
public:


    string reverseWords(string s) {
      int left = 0 ,right = -1;
      for(int i = 0 ; i < s.size() ; i++){
        if(s[i] == ' '){
          right = i - 1;
          while(left < right){
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            right--,left++;
          }
          left = i + 1;
        }
      }
      right = s.size()-1;
      while(left < right){
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        right--,left++;
      }
      return s;
    }

     string reverseWords(string s) {
      int left = 0 ,right = -1;
      for(int i = 0 ; i < s.size() ; i++){
        if(s[i] == ' '){
          while(left < right){
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            right--,left++;
          }
          left = i + 1;
          right = i;
        }else{
          right ++;
        }
      }
      while(left < right){
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        right--,left++;
      }
      return s;
    }


    string reverseWords(string s) {
      string res;
      string reverse;
      for(int i = 0 ; i < s.size() ; i++){
        if(s[i] == ' '){
          res += reverse + " ";
          reverse = "";
        }else{
          reverse =  s[i] + reverse;
        }
      }
      res += reverse;
      return res;
    }
};