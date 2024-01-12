# include <vector>
# include <string>

using namespace std;

class Solution {
public:
    bool makeEqual(vector<string>& words) {
      int size = words.size();
      if(size == 1) return true;
      vector<int> wordCount(26,0);

      for(string& word: words){
        for(char& c: word) wordCount[c-'a']++;
      }

      for(int i = 0 ; i < wordCount.size() ; i++){
        if(wordCount[i]%size != 0) return false;
      }

      return true;
    }
};