# include <string>
# include <unordered_map>

using namespace std;

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
      int count = 0;
      vector<int> countVect(26,0);
      for(char& c: chars){
        countVect[c-'a']++;
      }

      for(int i = 0 ; i < words.size() ; i++){
        vector<int> temp = countVect;
        bool isGood = true;

        for(char& c : words[i]){
          if(--temp[c-'a'] < 0){
              isGood = !isGood;
              break;
          }
        }

        if(!isGood) continue;
        count += words[i].size();
      }

      return count;
    }
};