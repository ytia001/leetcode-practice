#include "PlaceFlowers.hpp"

//solution
// bool canPlaceFlowers(vector<int>& flowerbed, int n) {
//         flowerbed.insert(flowerbed.begin(),0);
//         flowerbed.push_back(0);
//         for(int i = 1; i < flowerbed.size()-1; ++i)
//         {
//             if(flowerbed[i-1] + flowerbed[i] + flowerbed[i+1] == 0)
//             {
//                 --n;
//                 ++i;
//             }               
//         }
//         return n <=0;
//     }

 bool Solution::canPlaceFlowers(std::vector<int>& flowerbed, int n){
  int total = 0;
  int gaps = 0;
  int oneCount = 0;
  int endOne = std::count(begin(flowerbed),end(flowerbed),1);
  // takes care of gaps between 1 , 1 ---- 1
  // takes care of starting gaps before 1 , ----1
  for( int i : flowerbed){
    if(i){
      int available = 0;
      if(oneCount > 0 && oneCount < endOne){
        available = std::ceil((double)(gaps-2)/2);
      }else {
        available = gaps/2;
      }
      std::cout<<available<<std::endl;
      if(available>0) total += available;
      gaps = 0;
      oneCount ++;
    } else{
      gaps++;
    }
  }
  //std::cout<<"gaps"<<gaps<<std::endl;

  // takes care of gaps after last 1 , 1------
  // takes care of gaps without 1, -----
   if(gaps>0){
    if(oneCount>0 && oneCount == endOne){
      int available = std::ceil((double)(gaps-1)/2);
      if(available>0) total += available;
      gaps = 0;
    }else if (oneCount == 0){ //oneCount == endOne == 0
      total = std::ceil((double)(gaps)/2);
      gaps = 0;
    }
  }

  if(total < n) return false;
  return true;
 }

 int main(){
  Solution s;
  std::vector<int> test = {0};
  test.insert(test.begin(),0);
  test.push_back(0);
  for (int i :test ) std::cout<<i<<" "<<std::endl;
  //std::cout<<s.canPlaceFlowers(test,1)<<std::endl;
  // std::cout<<std::ceil((3-2)/2)<<std::endl;

  return 0;
 }