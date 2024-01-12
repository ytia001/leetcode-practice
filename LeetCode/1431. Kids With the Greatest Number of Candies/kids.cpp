#include <vector>
#include <iostream>
#include <algorithm>

std::vector<bool> kidsWithCandies(std::vector<int>& candies, int extraCandies) {
  std::vector<int> copy = candies;
  std::vector<bool> result(candies.size(),false);
  std::sort(copy.begin(),copy.end());
  int maxVal = copy[copy.size()-1];
  for(int i = 0 ; i < candies.size() ; i++){
    if((candies[i]+extraCandies)>= maxVal){
      result[i] = true;
    }
  }
  return result;
}

int main(){
  std::vector<int> test = {12,1,12};
  std::vector<bool> result = kidsWithCandies(test,10);
  for (auto i : result) std::cout<<i<<std::endl;
  return 0;
}

