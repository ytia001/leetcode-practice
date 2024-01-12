#include <string>
#include <unordered_set>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int res = 0;
        for(char c: jewels){
          res += count(stones.begin(),stones.end(),c);
        }
        return res;
    }

     int numJewelsInStonesTest(string jewels, string stones) {
        int res = 0;
        unoredered_set<char> jewelSet(jewels.begin(),jewels.end());
        //set<char> jewelSet(jewels.begin(),jewels.end());
        for(char c: stones){
          if(jewelSet.count(c)){
            res++;
          }
        }
        return res;
    }
};

int main(){
  Solution s;
  string jewel = "aA";
  string stones = "aAAbbbb";
  
  cout<<s.numJewelsInStonesTest(jewel,stones)<<endl;
  return 0;
}