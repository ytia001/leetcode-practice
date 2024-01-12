#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int points = obstacles.size(); 
        vector<vector<int>> tempLane = {{0},{2,3},{1,3},{1,2}};
        int currentLane = 2;
        int sideJumps = 0;
        for (int i = 0 ; i < points-1 ; i++){
          if(obstacles[i+1] == currentLane){
            cout<<"i: "<<i<<endl;
            if(obstacles[i]==0){
              sideJumps++;

              int firstTempLane = tempLane[obstacles[i+1]][0];
              int secTempLane =  tempLane[obstacles[i+1]][1];
              
              auto firstItr = find(obstacles.begin()+i,obstacles.end(),firstTempLane);
              auto secItr = find(obstacles.begin()+i,obstacles.end(),secTempLane);

              // if(firstItr == obstacles.end() ){
              //   currentLane = firstTempLane;
              // }else if(secItr == obstacles.end() ){
              //   currentLane = secTempLane;
              // }else{
              //   //(*firstItr >= *secItr) ? currentLane = firstTempLane : currentLane = secTempLane;
              //   int diff = firstItr - secItr;
              //   cout<<"diff: "<<diff<<endl;
              //   (diff >= 0) ? currentLane = firstTempLane : currentLane = secTempLane;
              // }

               int diff = firstItr - secItr;
               cout<<"diff: "<<diff<<endl;
               (diff >= 0) ? currentLane = firstTempLane : currentLane = secTempLane;

            }else{
              currentLane = 6 - obstacles[i+1] - obstacles[i];
              sideJumps++;
            }
          }
        }

        return sideJumps;
    }
};

int main(){
  Solution s;
  vector<int> obstacles = {0,2,1,0,3,0};
  //vector<int> obstacles = {0,0,3,1,0,1,0,2,3,1,0};
  cout<<s.minSideJumps(obstacles)<<endl;
  return 0;
}