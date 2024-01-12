#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:

    vector<int> getAverages(vector<int>& nums, int k) {
      vector<int> res(nums.size());
      vector<int> cal;
      int current = 0;
      int count = 0;

      for(int i = 0 ; i < nums.size() ; i++){
        current += nums[i];
        count++;
        if(count==(2*k+1)){
          cal.push_back(current/(2*k+1));
          current -= nums[i-(2*k)];
          count--;
        }
      }

      for(int i = 0 ; i < nums.size() ; i++){
       if(i-k < 0 || i+k > nums.size()-1){
        res[i] = -1;
        continue;
       }
        res[i] = cal[i-k];
      }

      return res ;
    }


    int avg(vector<int>& sums, int i , int k){
      if( i-k < 0 || i+k >= sums.size()-1) return -1;
      //cout<<"skdn:  "<<sums[i+1+k]-sums[i-k]<<endl;
      return (sums[i+1+k]-sums[i-k])/((2*k)+1);

    }

    vector<int> getAveragesTest(vector<int>& nums, int k) {
      vector<int> sums(nums.size()+1,0);
      vector<int> res(nums.size());
      for(int i = 0 ; i < nums.size() ;i++){
        sums[i+1] = nums[i] + sums[i];
      } 

      for(int i = 0 ; i < nums.size() ; i++){
        res[i] = avg(sums,i,k);
      }

      return res ;
    }
};

int main(){
    Solution s;
    vector<int> input = {7,4,3,9,1,8,5,2,6};
    vector<int> sol = s.getAverages(input,3);
    for(int i : sol){
      cout<<i<<endl;
    }
    return 0;
}