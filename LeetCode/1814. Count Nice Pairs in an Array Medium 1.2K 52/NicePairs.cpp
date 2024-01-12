#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    const int mod = 1e9 + 7;

    int rev(int input){
      string str = to_string(input);
      int output = 0;
      for(int i = str.size()- 1; i>=0 ; i--){
        output = (output*10) + (str[i]-'0');
      }

      return output;
    }

    int countNicePairs(vector<int>& nums) {
      unordered_map<int,int> mp;
      int res = 0;

      for(int i = nums.size()-1 ; i >=0 ; i--){
        int diff = rev(nums[i]) - nums[i];
        if(mp.count(diff)){
          res += mp[diff]%mod;
        }
        mp[diff]++;
      }
      return res;
    }
};