#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

bool comparator ( const int& a , const int& b){
      return a%2 < b%2;
    }

class Solution {
public:
    vector<int> Answer(vector<int> &A) {
        for (int i = 0, j = 0; j < A.size(); j++)
            if (A[j] % 2 == 0) swap(A[i++], A[j]);
        return A;
    }

    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0;
        int j = nums.size()-1;
        while(i<j){
          if(nums[i]%2==0){
            i++;
            continue;
          }
          
          if (nums[j]%2!=0){
            j--;
          }else{
            // int temp = nums[j];
            // nums[j--] = nums[i];
            // nums[i++] = temp;
            swap(nums[j--],nums[i++]);
          }
        }
        return nums;
    }

    vector<int> sortArrayByParityTest(vector<int>& nums) {
        sort(nums.begin(),nums.end(),comparator);
        return nums;
    }
};  

int main(){
  Solution s;
  vector<int> test = {0,1,2,3,4,5,6,7,8,9,10};
  vector<int> result = s.sortArrayByParity(test);
  for(int i : result){
    cout<<i<<endl;
  }
  return 0;
}