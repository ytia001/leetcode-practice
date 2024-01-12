#include <string>
#include <iostream>
#include <algorithm>

class Solution {
public:
     int Answer(std::string s) {
        int res = 0, cur = 0;
        for (char& c: s) {
            if (c == '(')
                res = std::max(res, ++cur);
            if (c == ')')
                cur--;
        }
        return res;
    }

    int maxDepth(std::string s) {
        int max = 0;
        int bracketCount = 0;
        for(int i = 0 ; i< s.size() ; i++){
          if(s[i]-'('== 0 ){
            ++bracketCount;
            if(bracketCount>max){
               max = bracketCount;
            }    
          }else if (s[i]-')'==0){
            --bracketCount;
          }    
            
        }
        return max;
    }

   int maxDepth2(std::string s) {
    int max = 0;
    for(int i = 0 ; i< s.size() ; i++){
        if(s[i]-'('== 0 ){
          max++;
        }    
      }
    return max;
   }
};

int main(){
  Solution s;
  std::string test = "()";
  std::cout<<s.maxDepth(test)<<std::endl;
  return 0;
}