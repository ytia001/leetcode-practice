#include "same3Digit.hpp"

std::string Solution::largestGoodInteger(std::string num){
  int largestDigit = 0;
  std::string largestStr;
  // std::unordered_map<int,std::string> map;
  int dupe = 0;
  for (int i=0; i < num.length() ; i++){
    char prevChar;
    if ( i==0 ) {
      prevChar = NULL;
    }else{
      prevChar = num[i-1];
    }

    if (num[i] == prevChar){
      dupe ++;
      if (dupe == 2 ){ 
        int digit = (int)(num[i])-48;
        //std::cout << digit << std::endl;
        if ( digit >= largestDigit){
        //map.insert({num[i-1],num.substr((int)(i-3)-48,i-1)}); 
        largestDigit = digit;
        largestStr = num.substr(i-2,3);
        //std::cout << largestStr << std::endl;
        }
       }
      

    }else{
      //std::cout << dupe << std::endl;
      dupe = 0;
      continue;
    
    }
  }
  // std::cout << "a'dfa" << std::endl;
 
  // for (const auto& pair : map) {
  //   if (pair.first> largestDigit){
  //     largestDigit = pair.first;
  //   } 
  // }
  // return largestStr = map.at(largestDigit);
  if (largestStr.size()){
    return largestStr;
  }
  return "";

}
int main(){
  Solution s1;
  std::cout << s1.largestGoodInteger("74444") << std::endl;
  return 0;
}