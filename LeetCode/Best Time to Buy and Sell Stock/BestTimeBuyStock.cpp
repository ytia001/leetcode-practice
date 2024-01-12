#include "BestTimeBuyStock.hpp"

 int Solution::maxProfit(std::vector<int>& prices){
  
  
  for (int i = 0; i < prices.size() ; i ++){
   
  }
  return 0;
 };

 int main(){
  std::vector<int> test = {7,6,4,3,1};
  Solution s1;
  std::cout << s1.maxProfit(test) << std::endl;
 }
 
//  std::map<int,int> priceIndexMap;
//   for (int i = 0; i < prices.size() ; i ++){
//     if ( !priceIndexMap.count(prices[i])){
//     priceIndexMap[prices[i]] = i;
//     }else{
//       continue;
//     }
//   }
//   for ( const auto& i : priceIndexMap){
//     std::cout<< i.first <<"\t" << i.second << std::endl;
//   }
//   return 0;
 
  // for (int i = 0 ; i< prices.size()-1; i++){
  //   int firstPrice = prices[i];
  //   std::vector<int> remainingPrices(prices.begin()+i+1,prices.end());
  //   std::sort(remainingPrices.begin(),remainingPrices.end());
  //   int maxPrice = remainingPrices[remainingPrices.size()-1];
  //   int currentprofit = maxPrice - firstPrice;
  //   if(currentprofit>0 && currentprofit>maxProfit){
  //     maxProfit = currentprofit;
  //   }
  // }
  // return maxProfit;