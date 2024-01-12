#include "RemoveAll.hpp"

// string removeOccurrences(string s, string part) {
// 	string x = s;
// 	int n = s.size(), m = part.size(), i, j;
// 	for (i = 0, j = 0; i < n; i++) {
// 		x[j++] = s[i];
// 		if (j >= m && x.substr(j - m, m) == part)
// 			j -= m;
// 	}
// 	return x.substr(0, j);
// }

std::string Solution::removeOccurrences(std::string s, std::string part){
  int length = part.size();
  auto it = s.find(part);
  while(it !=std::string::npos){
    // std::cout<<it<<std::endl;
    s.erase(it,length);
    // std::cout<<s<<std::endl;
    it = s.find(part);
  }
  return s;
}

int main(){
  std::string test = "axxxxyyyyb";
  Solution s;
  std::string result = s.removeOccurrences(test,"xy");
  std::cout<<result<<std::endl;
  return 0;
}