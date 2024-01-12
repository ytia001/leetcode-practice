# include <vector>

using namespace std;

class Solution {
public:
    int binarySearch(vector<int>& vect, int val){
      int l = 0 ;
      int r = vect.size() - 1;
      while(l<r){
        int mid = l + (r-l)/2;
        if(vect[mid] > val){
          r = mid;
        }else{
          l = mid + 1;
        }
      }
      return l;
    }

    int lengthOfLIS(vector<int>& nums) {
      vector<int> collec;
      collec.push_back(nums[0]);
      int res = 1;

      for(int i = 1; i < nums.size() ; i++){
        int idx = binarySearch(collec,nums[i]);
        if(nums[i] > collec[idx]){
          collec.push_back(nums[i]);
        }else{
          collec[idx] = nums[i];
        }
      }

      return collec.size();
    }
};