#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      vector<int> res;
      unordered_map<int,int> mp;
      int currentMax = INT_MIN;
      for(int i = 0 ; i < nums.size() ; i++){
        if(i<k){
          mp[nums[i]]++;
          currentMax = max(currentMax,nums[i]);
          if(i==k-1) res.push_back(currentMax);
          continue;
        }
        mp[nums[i]]++;
        mp[nums[i-k]]--;

        if(nums[i]>currentMax){
          currentMax = nums[i];
        }

        if(nums[i-k]==currentMax && mp[nums[i-k]]==0){
          currentMax = *max_element(nums.begin()+(i-k),nums.begin()+i);
        }

        res.push_back(currentMax);
       
      }

      return res;
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      vector<int> res;
      map<int,int> mp;
      int currentMax = INT_MIN;
      for(int i = 0 ; i < nums.size() ; i++){
        if(i<k){
          mp[nums[i]]++;
          currentMax = max(currentMax,nums[i]);
          if(i==k-1) res.push_back(currentMax);
          continue;
        }

        mp[nums[i]]++;
        // if(nums[i]>currentMax){
        //   currentMax = nums[i];
        // }
        if(--mp[nums[i-k]] == 0){
          mp.erase(nums[i-k]);
        }

        auto largestPair = mp.rbegin();
        currentMax = largestPair->first;
        res.push_back(currentMax);
      }

      return res;
    }
};