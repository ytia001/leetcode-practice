#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:

     bool canPartition(vector<int>& nums) {
      int total = accumulate(nums.begin(),nums.end(),0);
      if(total%2!=0) return false;
      int target = total/2;

      priority_queue<int,vector<int>,greater<>> pq1;
      priority_queue<int,vector<int>,less<>> pq2; 
      int sum1 = 0 , sum2 = 0 ;

      for(int i = 0 ; i < nums.size() ; i++ ){
        sum1 += nums[i];
        sum2 += nums[i];
        pq1.push(nums[i]);
        pq2.push(nums[i]);
        if(sum1 == target || sum2 == target) return true;
        while(sum1 > target){
          sum1 -= pq1.top();
          pq1.pop();
        }

        while(sum2 > target){
          sum2 -= pq2.top();
          pq2.pop();
        }
      }
      return false;
     }

     bool canPartition(vector<int>& nums) {
      int total = accumulate(nums.begin(),nums.end(),0);
      if(total%2!=0) return false;
      int target = total/2;
      sort(nums.begin(),nums.end());

      int left = 0;
      int current = 0;

      while(left<nums.size()-1){
        current += nums[left];
        if(current==target){
          return true;
        }
        if(current>=target) break;

        int dummy = current;
        int right = nums.size()-1;
        while(left<right){
          if(dummy+nums[right]==target){
            return true;
          }
          if(dummy+nums[right]>target){
            break;
          }
          dummy += nums[right--];
        }
        left++;
      }

      return false;
    }


    bool backtrack(vector<int>& nums,int current, int target,unordered_set<int>& idxHistory){
      if(current==target){
        return true;
      }

      if(current>target){
        return false;
      }

      for(int i = 0 ; i < nums.size() ; i++){
        if(idxHistory.count(i)) continue;
        idxHistory.insert(i);
        current += nums[i];
        if(backtrack(nums,current,target,idxHistory)) return true;
        idxHistory.erase(i);
        current -= nums[i];
      }

      return false;
    }

    bool canPartition(vector<int>& nums) {
      int total = accumulate(nums.begin(),nums.end(),0);
      if(total%2!=0) return false;
      int target = total/2;
      unordered_set<int> idxHistory;
      return backtrack(nums,0,target,idxHistory);
    }

    bool canPartition(vector<int>& nums) {
      int left = 0 , right = 0;
      sort(nums.begin(),nums.end());
      for(int i = nums.size()-1 ; i >=0 ; i--){
        if(left>right){
          right += nums[i];
        }else{
          left += nums[i];
        }
      }

      return left==right;
    }
};