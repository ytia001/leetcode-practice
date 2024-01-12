# include <vector>
# include <algorithm>

using namespace std;

class Solution {
public:

    bool check(vector<int>& nums){
      if(nums.size() < 2) return true;
      int d = nums[1] - nums [0];
      for(int i = 2 ; i < nums.size() ; i ++){
        if(nums[i]-nums[i-1] != d) return false;
      }
      return true;
    }

    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
      vector<bool> res(l.size(),false);
      vector<vector<int>> history(l.size(),vector<int>(r.size(),-1));
      for(int i = 0 ; i < l.size() ; i++){
        if(history[l[i]][r[i]] == -1){
          vector<int> temp(nums.begin()+l[i],nums.begin()+r[i]+1);
          sort(temp.begin(),temp.end());
          history[l[i]][r[i]] = check(temp) == 1 ? 1 : 0; 
        }
        res[i] = history[l[i]][r[i]] ;
      }

      return res;
    }
};