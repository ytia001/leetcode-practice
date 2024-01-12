#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT_MAX;
        int i = 0, j;
        int current = 0;
        for(j = 0; j<nums.size() ;j++){
          current += nums[j];
          while(i<=j && current>=target){
            res = min(res,j-i+1);
            current -= nums[i];
            i++;
          }
        }
        if(res == INT_MAX) return 0;
        return res;
    }
};