#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1;
        int r = *max_element(nums.begin(),nums.end());
        int total = 0;
        while(l<r){
          int mid = l + (r-l)/2;
          // transform(nums.begin(),nums.end(),copy.begin(),[&](double a){return ceil(a/mid);});
          // int total = accumulate(copy.begin(),copy.end(),0);
          total = 0;
          for(double i : nums){
            total += ceil(i/mid);
            //sum += (i + m - 1) / m; sum += ((i-1)/m) + 1;
          }
          if(total<=threshold){
            r = mid;
          }else{
            l = mid + 1;
          }
        }
        return l;
    }
};

int main(){
  Solution s;
  vector<int> nums = {44,22,33,11,1};
  cout<<s.smallestDivisor(nums,5)<<endl;
  return 0;
}