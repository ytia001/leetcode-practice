#include "RearrageCharToTarget.hpp"

int Solution::rearrangeCharacters(std::string s, std::string target){
  std::string filterChar = "";
  int total = 0 ;
  size_t currentIndex = 0;
  int targetIndex = 0;

  for ( int i = 0 ; i < s.size() ; i++ ){
    size_t currentIndex = target.find(s[i]);
    if( currentIndex!=std::string::npos){
      filterChar.push_back(s[i]);
    }
  }

    while(true){
      currentIndex = filterChar.find(target[targetIndex]);
      if( currentIndex!=std::string::npos){
      filterChar.erase(currentIndex,1);
        if(targetIndex == target.size()-1){
          total++;
          targetIndex = 0;
        }else{
        targetIndex++;
        }
      }else{
        break;
      }
    }
  
  return total;
}

int Solution::rearrangeCharactersSoln1(std::string s, std::string target){
  std::unordered_map<char,int> hm;
        for(auto c:s){
            hm[c]++;
        }
        int mn = INT_MAX;
        int cnt = 0;
        while(1){
            int i = 0;
            for(i;i<target.length();i++){
              //std::cout<<i<<std::endl;
                if(hm[target[i]]>0){
                    hm[target[i]]--;

                }
                else{
                    break;
                }
            }
            //std::cout<<"final:\t"<<i<<std::endl;
            if(i==target.length())
                cnt++;
            else
                break;
        }
        return cnt;
};

int main(){

  Solution s1;
  std::string test = "lrnvlcqukanpdnluowenfxquitzryponxsikhciohyostvmkapkfpglzikitwiraqgchxnpryhwpuwpozacjhmwhjvslprqlnxrk";
  std::cout<< s1.rearrangeCharactersSoln1(test,"woijih")<<std::endl;
  //std::size_t checking =  test.find('a');
  //std::cout<< checking  <<std::endl;
  return 0;
}

// for ( int i = 0 ; i < includedChar.size() ; i++){
//     size_t currentIndex = copy.find(s[i]);
//     if( currentIndex!=std::string::npos){
//       // std::cout<<s[i] <<"  ";
//       // std::cout<<currentIndex<<std::endl;
//       copy.erase(currentIndex,1);
//       if(copy.empty()){
//         total++;
//         copy = target;
//       }
//       }else{
//         //std::cout<<"y"<<" ";
//         continue;
//       }
//   }

//int Solution::rearrangeCharacters(std::string s, std::string target){
//   int total = 0 ;
//   int indexTarget = 0;
//   for ( int i = 0 ; i < s.size() ; i++){
//     if( s[i] == target[indexTarget]){
//       if(indexTarget == target.size()-1){
//         total ++;
//         indexTarget = 0;
//       }else{
//       indexTarget++;
//       }
//     }
//   }
//   return total;
// }