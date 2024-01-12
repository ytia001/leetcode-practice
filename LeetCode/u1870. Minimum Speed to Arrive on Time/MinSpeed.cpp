#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int size = dist.size();
        if(size-1 >= hour) return -1;

        int finalDist = dist[size-1];
        int TotalDist = accumulate(dist.begin(),dist.end(),0) - finalDist;

        int minSpeed = 1;
        int maxSpeed = max(*max_element(dist.begin(),dist.end()),(int)ceil((finalDist)/(hour-(size-1))));
        //cout<<"maxspeed: "<<maxSpeed<<endl;

        while(minSpeed<maxSpeed){
          int mid = minSpeed + (maxSpeed-minSpeed)/2;
          double currentHours = (double)TotalDist/mid + (double)finalDist/mid;
        }
        
    }
};