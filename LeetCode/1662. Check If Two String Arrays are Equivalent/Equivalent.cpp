# include <string>
# include <vector>

using namespace std;

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
      string s1,s2;
      int size = max(word1.size(),word2.size());

      for(int i = 0 ; i < size ; i++){
        if(i<word1.size()){
          s1 += word1[i];
        }
        if(i<word2.size()){
          s2 += word2[i];
        }
      }

      return s1==s2;
    }
};