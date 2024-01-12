#include "optimalPartition.hpp"

int Solution::partitionString(std::string s){
  int substringCount = 0;
  if(s.size()==0) return 0;

  std::vector<int> alphabetCount(26,0);
  std::vector<int> copy = alphabetCount;
  for (int i = 0 ; i < s.size() ; i++){
    int alphabet = s[i]-97;
    if(copy[alphabet]!=0){
      substringCount++;
      copy = alphabetCount;
      copy[alphabet] ++;
    }else{
      copy[alphabet]++;
    }
  }
  return substringCount+1;
}

int main(){
  //std::string test = "sssssss";
  //std::string test = "abacaba";
  std::string test = "abcdefg";
  Solution s;
  std::cout<<s.partitionString(test)<<std::endl;
  return 0;
}