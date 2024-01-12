#include"HandsOfStraights.hpp"

  // solution if (W < 1000)
  // bool isNStraightHand(vector<int> hand, int W) {
  //       map<int, int> c;
  //       for (int i : hand) c[i]++;
  //       for (auto it : c)
  //           if (c[it.first] > 0)
  //               for (int i = W - 1; i >= 0; --i)
  //                   if ((c[it.first + i] -= c[it.first]) < 0)
  //                       return false;
  //       return true;
  //   }

 bool Solution::isNStraightHand(std::vector<int>& hand, int groupSize){
  if (hand.size()%groupSize != 0) return false;
  std::sort(hand.begin(),hand.end());
  for(int i : hand) std::cout<<i<<std::endl;
  int numberOfGroup = hand.size()/groupSize;
  // std::vector<int> copy = hand;
  // std::vector<std::vector<int>> container(numberOfGroup,std::vector<int>(groupSize));
  
  int i = 0;
  while(i<=numberOfGroup){

  }

 };

 int main(){

  std::vector<int> test = {1,2,3,6,2,3,4,7,8};
  Solution s1;
  std::cout<< s1.isNStraightHand(test,3) << std::endl;
  return 0;
 }