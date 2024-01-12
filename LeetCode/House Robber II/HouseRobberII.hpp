#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int rob(std::vector<int>& nums);
    std::vector<int> sortByCash(std::vector<int>& nums);
    int largestSum (std::vector<int>& nums);
    int rob_max(std::vector<int>& nums,std::vector<std::pair<int,std::pair<int,int>>>& moneyNeighVect);
    std::vector<std::pair<int,std::pair<int,int>>> sortedMoneyNeighbourVector(std::vector<int>& nums);
};