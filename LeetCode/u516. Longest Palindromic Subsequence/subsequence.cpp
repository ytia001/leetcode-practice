#include <string>
#include <iostream>

void longestPalindromeSubseqTest(std::string s,int& total) {
    if(s.size()<=1) return;
    int dupe = 0;
    int i ;
    for (i = 0; i < s.size()-1;i++){
      // std::cout<<"s[i]: "<<s[i]<<"\ti+1: "<<i+1<<std::endl;
      std::size_t found = s.find(s[i],i+1);
      if(found !=std::string::npos){
        total += 2;
        std::string subString = s.substr(i+1,(found-i)-1);
        longestPalindromeSubseqTest(subString,total);
        i = found;
      }
    } 
    //std::cout<<"sdas"<<i<<std::endl;
    if(i<s.size()){
      if(s[i]==s[0]) total++;
    } 
    return;
}


int longestPalindromeSubseq(std::string s) {
     if(s.size()==1) return 1;
     if(s.size()<1) return 0;
     int count = 0;
     longestPalindromeSubseqTest(s,count);
     return count;
 }

// void countPalidrome(int startIdx , int endIdx , int& count){
//   if((endIdx - startIdx) ==)
// }
//int count = 0;


int main(){
  int result = longestPalindromeSubseq("baaaaab");
  std::cout<<result<<std::endl;
  // std::string test = "trytrr";
  // std::cout<<test.find("t",1)<<std::endl;
  return 0 ;
}
