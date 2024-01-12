#include <vector>
#include <queue>
#include <set>

using namespace std;

class Solution {
public:

    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<vector<int>,vector<vector<int>>,greater<>> pqX;
        priority_queue<vector<int>,vector<vector<int>>,greater<>> pqY;
        set<pair<int,int>> explored;

        for(auto& point : points){
          pqX.push({point[0],point[0],point[1]});
          pqY.push({point[1],point[0],point[1]});
        }

        pair<int,int> start = {pqX.top()[1],pqX.top()[2]}; pqX.pop();
        explored.insert(start);

        while (!pqX.empty())

    }
};