#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
     int lastStoneWeight(vector<int>& stones) {
        if(stones.size()==1) return stones[0];
        sort(stones.begin(),stones.end());
        int diff = stones[stones.size()-1] - stones[stones.size()-2];
        stones.pop_back();
        stones.pop_back();
        stones.push_back(diff);
        return lastStoneWeight(stones);
    }

    int lastStoneWeightTest(vector<int>& stones) {
        if(stones.size()==1) return stones[0];
        auto maxItr = max_element(stones.begin(),stones.end());
        int max1 = *maxItr;
        stones.erase(maxItr);
        maxItr = max_element(stones.begin(),stones.end());
        int diff = max1 - *maxItr;
        stones.erase(maxItr);
        stones.push_back(diff);
        return lastStoneWeight(stones);
    }
};

int main(){
  Solution s;
  //vector<int> test= {1};
  vector<int> test = {1,74,3,34,28,58,19,32,44,22,31,49,103};
  //cout<<s.lastStoneWeightTest(test)<<endl;
  cout<<s.lastStoneWeightTest(test)<<endl;
  return 0;
}