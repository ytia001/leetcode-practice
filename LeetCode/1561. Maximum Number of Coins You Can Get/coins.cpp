#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& piles) {
      int res = 0;
      sort(piles.rbegin(),piles.rend());
      for(int i = 1 ; i < piles.size() ; i += 3){
        res += piles[i];
      }

      return res;
    }
};