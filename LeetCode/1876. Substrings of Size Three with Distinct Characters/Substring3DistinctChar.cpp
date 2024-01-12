#include "Substring3DistinctChar.hpp"

// solution using sliding window technique
// int countGoodSubstrings(string s) {
//         if(s.size()<3)return 0;
//         char a=s[0],b=s[1],c=s[2];
//         int res=0;
//         for(int i=3;i<=s.size()-1;i++)
//         {
//             if(a!=b and b!=c and c!=a)res++;
//             a=b;
//             b=c;
//             c=s[i];
//         }
//         if(a!=b and b!=c and c!=a)res++;
//         return res;
//     }

int Solution::countGoodSubstrings(std::string s){
  int count = 0;
  if ( s.size() <= 2){
    return 0;
  }
  else{
  for ( int i = 0 ; i < s.size()-2 ; i++){
    if(s[i] != s[i+1] && s[i] != s[i+2] && s[i+1] != s[i+2] ){
      count++;
    }
  }
  }
  return count;
}

int main(){
  std::string test = "xyzzaz";
  Solution s1;
  std::cout<< s1.countGoodSubstrings(test) << std::endl;
  return 0;
}