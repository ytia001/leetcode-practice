#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {

       sort(nums.begin(),nums.end());

       int threshold = target/2; // min val threshold == individual minmax threshold equals <= target/2
       vector<long long> index(nums.size(),0);

       for(int start = 0 ; start < nums.size() ; start++){
          if(nums[start]>threshold){
            break;
          }
          int minVal = nums[start];
          for(int i = start ; i <nums.size() ; i++ ){
            long long add = 0;
            if(i==start){
              (i==nums.size()-1) ? index[i] += 1: index[i] = 1;
              continue;
            }
            // if(minVal + nums[i]<=target){
            //   index[i] = index[i-1]+pow(2,(i-start)-1);
            // }else{
            //   index[i] = index[i-1];
            // }

            // if(i==nums.size()-1){
            //   index[i] += index[i-1] + add;
            // }else{
            //   index[i] = index[i-1] +add;
            // }

            if(minVal + nums[i]<=target){
              add = pow(2,(i-start)-1);
            }

            (i==nums.size()-1) ?index[i] += index[i-1] + add : index[i] = index[i-1] +add;

          }
       }
       return index[nums.size()-1]%(1000000007);
    }


};

int main(){
  Solution s;
  vector<int> test = {7,10,7,3,7,5,4};
  cout<<s.numSubseq(test,12)<<endl;
  return 0;
}