#include "LengthLastWord.hpp"

int Solution::countLastWord (std::string s , int index, int length){

     if  (s[index] == ' ' && length != 0) {
      return length;
     } 
     if(index==0){
      return length+1;  
     } 
    return (s[index] != ' ')?  countLastWord(s,index-1,++length): countLastWord(s,index-1,length);
  }

// answer
// int lengthOfLastWord(string s) {
//         int n = s.size()-1;
//         while (n >= 0 && s[n] == ' ')
//             n--;
//         int count = 0;
//         while (n >= 0 && s[n] != ' ') {
//             count++;
//             n--;
//         }
//         return count;
//     }


int Solution::lengthOfLastWord(std::string s){
  
  return Solution::countLastWord(s,s.length()-1,0);
}

int main(){
  Solution s1;
  int output = s1.lengthOfLastWord("  Hell in the cells");
  std::cout<< output << std::endl;
  return 0;
}