#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
       int nom = coordinates[1][1]- coordinates[0][1];
       int denom = coordinates[1][0]- coordinates[0][0];
       if(nom==0){
        for(int i = 2 ; i<coordinates.size() ; i++){
          if(coordinates[i][1]-coordinates[i-1][1]!=0){
            return false;
          }
         }
       }
       else if (denom==0){
        for(int i = 2 ; i<coordinates.size() ; i++){
          if(coordinates[i][0]-coordinates[i-1][0]!=0){
            return false;
          }
         }
       }
       else{
        double gradient = (double)nom/denom;
        for(int i = 2 ; i<coordinates.size() ; i++){
          double new_gradient = (coordinates[i][1]- coordinates[0][1])/(double)(coordinates[i][0]- coordinates[0][0]);
          // cout<<"gradient: "<<gradient<<"new gradient"<<new_gradient<<endl;
          if(new_gradient!= gradient){
            return false;
          }
         }
       }
       return true;
    }

    // bool checkStraightLine(vector<vector<int>>& coordinates) {
    //    double gradient = (coordinates[1][1]-coordinates[0][1])/(coordinates[1][0]-coordinates[0][0]);
    //    double intercept = coordinates[0][1]-gradient*coordinates[0][0];
    //    for(int i = 2 ; i<coordinates.size() ; i++){
    //       int y_new = gradient*coordinates[i][0]+intercept;
    //       if(y_new!=coordinates[i][1]){
    //         return false;
    //       }
    //    }
    //    return true;
    // }
};

int main(){
  Solution s;
  vector<vector<int>> test = {{1,1},{2,2},{3,4},{4,5},{5,6},{6,7}};
  cout<<s.checkStraightLine(test)<<endl;
  return 0;
}