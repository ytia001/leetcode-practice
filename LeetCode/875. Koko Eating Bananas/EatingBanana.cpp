#include "EatingBanana.hpp"

//solutions
// class Solution {
// public:
//     long long getHoursToEatAll(vector<int>&piles, int bananasPerHour)
//     {
//         long long totalHours = 0;
//         for (int i = 0; i < piles.size(); i++)
//         {
//             int hoursToEatPile = ceil(piles[i] / (double)bananasPerHour);
//             totalHours += hoursToEatPile;
//         }
//         return totalHours;
//     }
//     int minEatingSpeed(vector<int>& piles, int targetHours)
//     {
//         int low = 1, high = *(max_element(piles.begin(), piles.end()));
//         int ans = -1;
//         //================================================================
//         while(low <= high)
//         {
//             int mid = low + (high - low) / 2;
//             long long hoursToEatAll = getHoursToEatAll(piles, mid);
            
//             if (hoursToEatAll <= targetHours)
//             {
//                 ans = mid; //record the answer (this is the best we could record till curr step)
//                 high = mid - 1;
//             }
//             else low = mid + 1;
//         }
//         //=================================================================
//         return ans;
//     }
// };

int Solution::minEatingSpeed(std::vector<int>& piles, int h){
  std::sort(piles.begin(),piles.end());
  // int left = piles[0];
  // int right = piles[piles.size()-1];
  int left = 1;
  int right = piles[piles.size()-1];

  while( left < right ){
    int mid = left + (right-left)/2;
    std::vector<double> copy(piles.begin(),piles.end());
    std::transform(copy.begin(),copy.end(),copy.begin(),[mid](double x){return std::ceil(x/mid);});
    int hoursNeeded = std::accumulate(copy.begin(),copy.end(),0);
    for (int i : copy) std::cout<<i<<"  ";
    std::cout<<"\nhours needed for "<<mid <<" banana per hour is: "<<hoursNeeded<<std::endl; 
    if(hoursNeeded > h){
      left = mid + 1;
    }else{
      right = mid;
    }
  }
  std::cout<<left<<"::"<<right<<std::endl;
  

  // for ( int i = 1; i <= right ; i++){
  //   std::vector<double> copy(piles.begin(),piles.end());
  //   std::transform(copy.begin(),copy.end(),copy.begin(),[i](double x){return std::ceil(x/i);});
  //   int hoursNeeded = std::accumulate(copy.begin(),copy.end(),0);
  //   for (int i : copy) std::cout<<i<<"  ";
  //   std::cout<<"\nhours needed for "<<i <<" banana per hour is: "<<hoursNeeded<<std::endl; 
  // }
  return left;
}

int main(){
  std::vector<int> test = {312884470};
  Solution s1;
  std::cout<<s1.minEatingSpeed(test,312884469)<<std::endl;
  return 0;
}