#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int currentMax = 0;
    int res = 0;
    unordered_set<int> history;

    void search(vector<int>& nums, int index , int prevNum, int count){
      if(index >= nums.size() || nums[index]<= prevNum || history.count(index)){
        return;
      }
      if(count>currentMax){
        res = 1;
        currentMax = count;
      }else if (count == currentMax){
        res++;
      }

      for(int i = index + 1 ; i < nums.size() ; i++){
        count += 1;
        search(nums,i,nums[index],count);
        count -=1;
      }
    }

    int findNumberOfLIS(vector<int>& nums) {
      int size = nums.size();
      for(int i = 0 ; i < nums.size() ; i++){
        if(history.count(i)) continue;
        search(nums,i,INT_MIN,1);
      }
      return res;
    }
};