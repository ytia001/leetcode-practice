#include<string>
#include<iostream>
#include<algorithm>

// string mergeAlternately(string w1, string w2) {
//         int n = w1.size(), m = w2.size(), i = 0, j = 0;
//         string res = "";
//         while (i < n || j < m) {
//             if (i < n)
//                 res.push_back(w1[i++]);
//             if (j < m)
//                 res.push_back(w2[j++]);
//         }
//         return res;
//     }

std::string mergeAlternately(std::string word1, std::string word2) {
  //int total= word1.size() + word2.size() - 2;
  std::string result = "";
  //std::string combine = word1 + word2;
  int minLength = std::min(word1.size(),word2.size());
  for (int i = 0 ; i < minLength ; i++){
    result.push_back(word1[i]);
    result.push_back(word2[i]);
  }
  // for (int i = 0 ; i < minLength ; i++){
  //   result.push_back(combine[i]);
  //   result.push_back(combine[word1.size()+i]);
  // }

  if(minLength>word1.size()-1){
    result.append(word2.substr(minLength));
  }else if(minLength>word2.size()-1){
    result.append(word1.substr(minLength));
  }
  return result;
}

int main(){
  std::string test = "abc";
  std::string test2 = "zz";
  //test2.push_back(test[10]);
  std::cout<<test2<<std::endl;
  return 0;
}