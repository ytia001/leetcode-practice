# include <string>

using namespace std;

class Solution {
public:

    int minOperations(string s) {
      int sum1 = 0 , sum2 = 0;
      char next1 = '0' , next2 = '1';

      for(int i = 0 ; i < s.size() ; i++){
        if(s[i] != next1){
          sum1++;
        }
        if(s[i] != next2){
          sum2++;
        }
        next1 =  next1 == '0' ? '1' : '0' ;
        next2 = next2 == '0' ? '1' : '0' ;
      }
      //cout<<"sum1: "<<sum1<<" sum2: "<<sum2<<endl;
      return min(sum1,sum2); 
    }


    int minOperations(string s) {
      int res = 0;
      for(int i = 1 ; i < s.size()-1; i++){
        if(s[i] == s[i] && s[i] == s[i+1] ){
          if(s[i] == '0') s[i] = '1';
          if(s[i] == '1') s[i] = '0';
          res++;
        }else{
          if(s[i] == s[i-1] || s[i] == s[i+1]){
            if(s[i] == s[i-1]) s[i-1] = s[i+1];
            if(s[i] == s[i+1]) s[i+1] = s[i-1];
            res++;
          }
        }
      }

      return res;
    }
};