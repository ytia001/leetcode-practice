#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <deque>

using namespace std;

class Solution {
public:
    // int kCalculator(deque<int>& dq, int sum){
    //   int k = 0;
    //   int currentSum = 0;
    //   while(!dq.empty()){
    //     if(currentSum + dq.back()<=sum){
    //       if(currentSum+dq.back()==sum){
    //         k++;
    //         currentSum = 0;
    //       }else{
    //         currentSum += dq.back();
    //       }
    //       dq.pop_back();
          
    //     }else if(currentSum + dq.front()<=sum){
    //       if(currentSum+dq.front()==sum){
    //         k++;
    //         currentSum = 0;
    //       }else{
    //         currentSum += dq.front();
    //       }
    //       dq.pop_front();
    //     }else{
    //       break;
    //     }
    //   }
    //   if(!dq.empty()||currentSum!=0) return -1;
    //   return k;
    // }

    int kCalculator(vector<int>& nums, int sum){
      sort(nums.begin(),nums.end());
      vector<int> copy = nums;
      int k = 0;
      int currentSum = 0;
      while(copy.size()){
        currentSum += copy[copy.size()-1];
        copy.pop_back();
        cout<<"current sum: "<<currentSum<<endl;
        if(currentSum == sum){
          k++;
          currentSum = 0;
          continue;
        }
        // for(int i = copy.size()-1; i>=0 ; i--){
        //   if(currentSum + copy[i]==sum){
        //       k++;
        //       currentSum = 0;
        //       copy.erase(copy.begin()+i);
        //   }
        // }
        int i = copy.size()-1;
        while(i>=0){
          if(currentSum + copy[i]<=sum){
            if(currentSum + copy[i]==sum){
              k++;
              currentSum = 0;
              copy.erase(copy.begin()+i);
              break;
            }else{
              currentSum += copy[i];
              copy.erase(copy.begin()+i);
            } 
          }
          i--;
        }
        // cout<<currentSum<<endl;
        //cout<<"currentK: "<<k<<endl;
        //if(currentSum>0 && currentSum!=sum) return -1;
      }
      if(currentSum!=0) return -1;
      return k;
    }


    bool canPartitionKSubsets(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int maxVal = *max_element(nums.begin(),nums.end());
        int maxSum = accumulate(nums.begin(),nums.end(),0);
        //deque<int> dq(nums.begin(),nums.end());
        // vector<int> container(maxVal+1);
        // for(int i : nums){
        //   container[i]++;
        // }
        for(int i = maxVal ; i<=maxSum ; i++){
          cout<<"i: "<<i<<endl;
          int currentK = kCalculator(nums,i);
          cout<<"currentK: "<<currentK<<endl;
          if(currentK==k) return true;
        }

        return false;
    }
};

int main(){
  Solution s;
  vector<int> nums = {1,2,3,4};
  int k = 3;
  //cout<<s.kCalculator(nums,5)<<endl;
  cout<<s.canPartitionKSubsets(nums,k)<<endl;
  return 0;
}