#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:

    int numIdenticalPairs(vector<int>& nums) {
      int res = 0;
      int count[101] = {0};
      for(int i = 0 ; i < nums.size() ; i++){
        if(count[nums[i]]){
          res += count[nums[i]];
        }
        count[nums[i]]++;
      }
      return res;
    }

    int numIdenticalPairs(vector<int>& nums) {
      int res = 0;
      unordered_map<int,int> mp;
      // int count[101];
      for(int i = 0 ; i < nums.size() ; i++){
        if(mp.count(nums[i])){
          res += mp[nums[i]];
        }
        mp[nums[i]]++;
      }
      return res;
    }
};