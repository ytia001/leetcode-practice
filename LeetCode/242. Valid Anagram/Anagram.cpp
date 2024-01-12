#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:

    // bool isAnagram(string s, string t) {
    //   int identical = 0;
    //   if(s.size()!=t.size()) return false;
    //   for(int i = 0 ; i < s.size() ; i++){
    //     identical = identical ^ s[i] ^ t[i];
    //   }
    //   return identical;
    // }

    bool isAnagram(string s, string t) {
      unordered_map<char,int> charMap;
      if(s.size()!=t.size()) return false;
      for(auto c: s){ 
        charMap[c]++;
      }
      for(auto c: t){
        if(!charMap.count(c) || charMap[c]==0) return false;
        charMap[c]--;
      }
      return true;
    }
};