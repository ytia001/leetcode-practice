# include <cstdint>
# include <string>

using namespace std;

class Solution {
public:

    int hammingWeight(uint32_t n) {
      int count = 0;
      for(int i = 0 ; i < 32 ; i++){
        uint32_t mask = 1 << i;
        if(n & mask){
          count++;
        }
      }
      return count;
    }

    int hammingWeight(uint32_t n) {
      int count = 0;
      for(int i = 0 ; i < 32 ; i++){
        uint32_t test = n & 1;
        if(test){
          count++;
        }
        n = n >> 1;
      }
      return count;
    }
};