#include "FairCandySwap.hpp"
using namespace std;
//SOLUTION WITH O(N) TIME COMPLEXITY
//Calculate dif = (sum(A) - sum(B)) / 2
//We want find a pair (a, b) with a = b + dif

vector<int> fairCandySwap(vector<int> A, vector<int> B) {
        int dif = (accumulate(A.begin(), A.end(), 0) - accumulate(B.begin(), B.end(), 0)) / 2;
        unordered_set<int> S(A.begin(), A.end());
        for (int b: B)
            if (S.count(b + dif))
                return {b + dif, b};
    }


//TOO SLOW !!!
// std::vector<int> Solution::fairCandySwap(std::vector<int>& aliceSizes, std::vector<int>& bobSizes){
//   std::vector<int> chosenAmounts ;
//   int aliceTotal = std::accumulate(aliceSizes.begin(),aliceSizes.end(),0);
//   int bobTotal = std::accumulate(bobSizes.begin(),bobSizes.end(),0);
//   int netAmountNeeded = ((bobTotal + aliceTotal)/2)-aliceTotal;
//   // std::cout<< "Net: "<<netAmountNeeded << std::endl;
//   int aliceChosenIndex;
//   int bobChosenIndex;

//   std::sort(aliceSizes.begin(),aliceSizes.end());
//   std::sort(bobSizes.begin(),bobSizes.end());

//   for (aliceChosenIndex = 0;aliceChosenIndex < aliceSizes.size();aliceChosenIndex++){
//     for (bobChosenIndex = 0;bobChosenIndex < bobSizes.size();bobChosenIndex++){
//       int netAmountForAlice = bobSizes[bobChosenIndex] - aliceSizes[aliceChosenIndex];
//       // std::cout<< "NetAmount: "<<netAmountForAlice << std::endl;
//       if( netAmountForAlice == netAmountNeeded){
//         chosenAmounts.push_back(aliceSizes[aliceChosenIndex]);
//         chosenAmounts.push_back(bobSizes[bobChosenIndex]);
//         return chosenAmounts;
//       }
//     }
//   }
//   return chosenAmounts;
// }

int main(){
  Solution s1;
  std::vector<int> aliceSizes = {1,3,6};
  std::vector<int> bobSizes = {3,4,7};
  std::vector<int> result = s1.fairCandySwap(aliceSizes,bobSizes);
  for(int i : result) std::cout<< i << std::endl;
  return 0;
}