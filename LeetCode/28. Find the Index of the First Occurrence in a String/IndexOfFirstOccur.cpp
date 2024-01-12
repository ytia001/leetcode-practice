#include "IndexOfFirstOccur.hpp"

// Brute force
//  int strStr(string haystack, string needle) {
//         int m = haystack.size(), n = needle.size();
//         for (int i = 0; i <= m - n; i++) {
//             int j = 0;
//             for (; j < n; j++) {
//                 if (haystack[i + j] != needle[j]) {
//                     break;
//                 }
//             }
//             if (j == n) {
//                 return i;
//             }
//         }
//         return -1;
//     }

int Solution::strStr(std::string haystack, std::string needle){
  std::size_t needleIndex = haystack.find(needle);
  std::size_t smallIndex = needleIndex;
  while(needleIndex != std::string::npos){
    if(needleIndex < smallIndex){
      smallIndex = needleIndex;
    }
    needleIndex = haystack.find(needle,needleIndex+needle.length());
  }
   std::cout<<smallIndex <<std::endl;
  if(smallIndex == std::string::npos){
    return -1;
  }else{
    return smallIndex;
  }
 
}

int main(){
  Solution s1;
  std::string haystack = "leetcodeisfornerdss";
  std::string needle = "let";
  std::cout<< s1.strStr(haystack,needle) <<std::endl;
  return 0 ;
}