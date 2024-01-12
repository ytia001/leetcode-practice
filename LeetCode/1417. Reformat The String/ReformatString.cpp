#include "ReformatString.hpp"

//  solution
//  string reformat(string s) {
//         string a="",d="";
//         // split string into alpha string and digit strings
//         for(auto x:s)
//             isalpha(x)?a.push_back(x):d.push_back(x);
  
//         // if difference is more than 1, return "" since not possible to reformat
//         if(abs(int(a.size()-d.size()))>1)
//             return "";
//         // merge the strings accordingly, starting with longer string
//         bool alpha=a.size()>d.size();
//         int i=0,j=0,k=0;
//             while(i<s.size()){
//                 if(alpha){
//                     s[i++]=a[j++];
//                 }
//                 else{
//                     s[i++]=d[k++];
//                 }
//                 alpha=!alpha;
//             }
//         return s;
//     }

std::string Solution::reformat(std::string s){
  std::vector<char> charArray;
  std::vector<char> intArray;
  std::string resultString = "";
  for ( int i = 0 ; i < s.length() ; i ++){
    int asciiVal = (int) s[i];
    if (asciiVal >=97  && asciiVal <= 122){
      charArray.push_back(s[i]);
      // std::cout<<"1"<<std::endl;
    }else{
      intArray.push_back(s[i]);
      // std::cout<<"2"<<std::endl;
    }
  }
  
  int difference = charArray.size()-intArray.size();
  difference = abs(difference);
  std::cout<<charArray.size()<<"::"<<intArray.size()<<"Diff: "<<difference<<std::endl;
  if (difference<= 1){
    if ( charArray.size() > intArray.size()){
      int i = 0;
      for(; i < intArray.size() ; i++){
         resultString.push_back(charArray[i]);
         resultString.push_back(intArray[i]);
      }
         resultString.push_back(charArray[i]);
         return resultString;
    }else if ( charArray.size() < intArray.size()){
      int i = 0;
      for(; i < charArray.size() ; i++){
         resultString.push_back(intArray[i]);
         resultString.push_back(charArray[i]);
      }
         resultString.push_back(intArray[i]);
         return resultString;
    }else{
      for( int i = 0 ; i<charArray.size() ; i++){
        resultString.push_back(charArray[i]);
        resultString.push_back(intArray[i]);
      }
      return resultString;
    }
  }else{
    return "";
  }
};

int main(){
  std::string test= "1229857369";
  Solution s1;
  std::cout<< s1.reformat(test) << std::endl;
  return 0;
}