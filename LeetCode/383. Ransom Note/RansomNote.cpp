#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:

    bool canConstruct(string ransomNote, string magazine) {
      if(ransomNote.size()>magazine.size()) return false;
      vector<int> alphabet(26,0);
      for(int i = 0 ; i < ransomNote.size() ; i++){
        alphabet[ransomNote[i]-'a'] ++;
      }
      for(int i = 0 ; i < magazine.size() ; i++){
        if(alphabet[magazine[i]-'a']>0){
          alphabet[magazine[i]-'a'] --;
        }else{
          continue;
        }
      }
      for(int i : alphabet){
        if(i) return false;
      }
      return true;
    }
};