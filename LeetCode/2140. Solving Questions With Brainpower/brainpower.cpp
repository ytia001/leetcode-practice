#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    long long mostPointsTest(vector<vector<int>>& questions) {
      vector<long long> container(questions.size()+2,0);
      int size = questions.size(); 
      for(int i = size ; i > 0 ; i--){
        int prevIdx = i + questions[i-1][1] + 1;
        long long currentMax = 0;
        if( prevIdx > size){
           currentMax = questions[i-1][0] + 0;
        }else{
           currentMax = questions[i-1][0] + container[prevIdx];
        }
        container[i] = max(currentMax,container[i+1]);
      }

      return container[1];
    }


    // long long mostPointsTest1(vector<vector<int>>& questions) {
    //     long long res = 0;
    //     vector<vector<long long>> container;
    //     for (auto i : questions){
          
    //       if(!container.empty()){
    //         for(auto& k: container){
    //           k[1]--;
    //           if(k[1] < 0){
    //             k[0] += i[0];
    //             k[1] = i[1];
    //             res = max(res,k[0]);
    //             //continue;
    //           }
    //           //k[1]--;
    //           //cout<<"k[0]: "<<k[0]<<" k[1]: "<<k[1]<<endl;
    //         }
    //       }
    
    //       vector<long long> newInput = {i[0],i[1]};
    //       //cout<<i[0]<<" "<<i[1]<<endl;
    //       container.push_back(newInput);
    //     }

        
    //     return res;
    // }

    // long long mostPointsTest2(vector<vector<int>>& questions) {
    //     long long res = 0;
    //     vector<vector<long long>> container;
    //     for (auto i : questions){
          
    //       if(!container.empty()){
    //         int containerSize = container.size();
    //         for(int k = 0; k<containerSize ; k++){
    //           container[k][1]--;
    //           if(container[k][1] < 0){
    //             container.push_back({container[k][0],0});
    //             container[k][0] += i[0];
    //             container[k][1] = i[1];
  
    //           }
    //         }
    //       }
    
    //       vector<long long> newInput = {i[0],i[1]};
    //       container.push_back(newInput);
    //     }

    //     for(auto i : container){
    //       res = max(res,i[0]);
    //     }

    //     return res;
    // }

    // long long mostPointsTest3(vector<vector<int>>& questions) {
    //    vector<vector<long long>> container(questions.size()+1, vector<long long>(2, 0));
    //   //long long container[questions]
    //   int m = questions.size();

    //   for(int i = 1; i <= m ; i++){
    //     int t = questions[i-1][1];
    //     for(int j = i ; j<= m ; j++){
    //         //int t = questions[j-1][1];

    //         if(t-- < 0){
    //           if(i==j){
    //             container[i][j] = max(container[i-1][m],(long long) questions[i-1][0]);
    //           }
    //           else{
    //             container[i][j] = max(container[i][j-1],(long long) questions[i-1][0]+(long long)questions[j-1][0]);
                
    //           }

    //         }else{
    //           container[i][j] = container[i][j-1];
    //         }
    //     }
    //   }
    // }

  
};

int main(){
  Solution s;
  //vector<vector<int>> test = {{3,2},{4,3},{4,4},{2,5}};
  //vector<vector<int>> test = {{1,1},{2,2},{3,3},{4,4},{5,5}};
  //vector<vector<int>> test = {{21,5},{92,3},{74,2},{39,4},{58,2},{5,5},{49,4},{65,3}};
  vector<vector<int>> test = {{43,5}};
  cout<<s.mostPointsTest(test)<<endl;
  return 0 ;  
}