#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
   bool PredictTheWinner(vector<int>& nums) {
      int l = 0;
      int r = nums.size()-1;
      long long playerOne = 0 ;
      long long playerTwo = 0;
      bool oneTurn = true;
      while(l<r){
        int nextL = l+1;
        int nextR = r-1;

        if(oneTurn){
          long long leftNext = nums[nextL] + nums[r];
          long long rightNext = nums[l] + nums[nextR];
          if(nextL==r) leftNext /= 2; 
          if(nextR==l) rightNext /= 2;
          cout<<"leftNext: "<<leftNext<<" rightNext: "<<rightNext<<endl;
          if(leftNext>=rightNext){
            playerOne += nums[r];
            r--;
          }else{
            playerOne += nums[l];
            l++;
          }
        }else{
          long long leftNext = nums[nextL] + nums[r];
          long long rightNext = nums[l] + nums[nextR];
          if(nextL==r) leftNext /= 2; 
          if(nextR==l) rightNext /= 2;
          cout<<"leftNext: "<<leftNext<<" rightNext: "<<rightNext<<endl;
          if(leftNext>=rightNext){
            playerTwo += nums[r];
            r--;
          }else{
            playerTwo += nums[l];
            l++;
          }
        }
        !oneTurn;
        cout<<"left: "<<l<<" right: "<<r<<endl;
      }
      if(oneTurn) playerOne += nums[l];
      else{
        playerTwo += nums[r];
      }
      
      return playerOne >= playerTwo; 
    }
};