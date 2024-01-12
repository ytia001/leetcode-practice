#include<vector>
#include<iostream>
#include<algorithm>
#include<numeric>

class Solution {
public:
    long long minimumTime(std::vector<int>& time, int totalTrips);
    long long currTotalTime(std::vector<int>& time,int totalTrips,int startIndex);
};