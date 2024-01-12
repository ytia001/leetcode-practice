# include <vector>
# include <map>

using namespace std;

class Solution {
public:

    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
      int m = nums.size();
      vector<int> res;
      map<int,vector<int>> mp;

      for(int i = 0 ; i < nums.size() ; i++){
        for(int j = 0 ; j < nums[i].size(); j++){
          mp[i+j].insert(mp[i+j].begin(),nums[i][j]);
        }
      }

      for(auto& elem : mp){
        for( int val : elem.second){
          res.push_back(val);
        }
      }

      return res;
    }


    // vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
    //    int m = nums.size(),  n = 0;
    //   for(auto num: nums){
    //     n = max(n,(int)num.size());
    //   }
    //   vector<int> res;
    //   cout<<"n: "<<n<<endl;
    //   for(int s = 0 ; s < 2*max(m,n)-1 ; s++){
    //     if(s < max(m,n)){
    //         for(int i = s ; i >= 0 ; i--){
    //             if(i >= m) break;
    //             int j = s-i;
    //             if(j >= nums[i].size()) continue;
    //             res.push_back(nums[i][j]);
    //         }
    //     }
    //     else{
    //         for(int i = m - 1 ; i > s%m ; i--){
    //             if(i >= m) break;
    //             int j = s-i;
    //             if(j >= nums[i].size()) continue;
    //             res.push_back(nums[i][j]);
    //         }
    //     }
    //   }

    //   return res; 
    // }
};