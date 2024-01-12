#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
      int res = 100;
      set<int> set1(nums1.begin(),nums1.end());
      int min1 = *set1.begin();
      int min2 = 100;
      for(int i : nums2){
        if(set1.count(i)){
          res = min(res,i);
        }
        min2 = min(min2,i);
      }
        
      //return min(res,min((min1*10)+min2,(min2*10)+min1));
      return min(res,min(min1,min2)*10+max(min1,min2));
    }

};

int main(){
  Solution solution;
  vector<int> nums1 = {3,1,7};
  vector<int> nums2 = {3,5,2,6};
  cout<<solution.minNumber(nums1,nums2)<<endl;

  return 0;
}