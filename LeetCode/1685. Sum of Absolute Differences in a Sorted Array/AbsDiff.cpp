#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:

    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
      int size = nums.size();
      int total = accumulate(nums.begin(),nums.end(),0), current = 0;
      vector<int> res(nums.size(),0);

      for(int i = 0; i < size; i++){
        current += nums[i];
        res[i] =  ((i+1)*nums[i] - current) + ((total-current) - ((size-1-i)*nums[i]));
      }

      return res;
    }


    // vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
    //   int total = nums.size()-1;
    //   vector<int> res(nums.size(),0);
    //   vector<int> sumVect(nums.size(),0);
      
    //   for(int i = 0, cumulativeSum = 0; i <sumVect.size(); i++){
    //     sumVect[i] = cumulativeSum;
    //     cumulativeSum += nums[i];
    //   }
    //   for(int i = sumVect.size()-2 , cumulativeSum = 0 ; i >= 0 ; i--){
    //     sumVect[i] = cumulativeSum;
    //     cumulativeSum += nums[i];
    //   }

    //   for(int i = 0 ; i < sumVect.size() ; i++){
    //     res[i] = sumVect[i] - total*nums[i];
    //   }

    //   return res;
    // }
};