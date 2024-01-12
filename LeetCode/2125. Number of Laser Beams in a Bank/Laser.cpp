# include <vector>
# include <string>

using namespace std;

class Solution {
public:
    int countOne(string s){
      int count  = 0;
      for(char& c: s){
        if(c == '1') count ++;
      }
      return count;
    }

    int numberOfBeams(vector<string>& bank) {
      int res = 0;
      int prev = countOne(bank[0]);
      for(int i = 1 ; i < bank.size() ; i++){
        int cur = countOne(bank[i]);
        res += (cur*prev);
        if(cur != 0) prev = cur;
      }
      return res;
    }
};