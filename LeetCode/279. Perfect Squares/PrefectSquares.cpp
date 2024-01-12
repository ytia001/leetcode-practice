#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

class Solution {
public:

    // bool isPerfectSquare(int n){
    //   return sqrt(n)*sqrt(n)==n;
    // }


    int numSquares(int n) {
      //priority_queue<int,vector<int>,less<>> pq;
      int res = INT_MAX;
      vector<int> container;
      for(int i = 1 ; i <= n ; i++){
        int square = i*i;
        if(square>n) break;
        container.push_back(square);
      }
      // cout<<container.size()<<endl;
      for(int i = container.size()-1;i>=0;i--){
        int current = n;
        int total = 0;
        for(int j = i ; j>=0 ; j--){
          if(current<=0) break;
          total += current/container[j];
          current = current%container[j];
        }
        res = min(res,total);
      }
      return res;
    }
};

int main(){
  Solution s;
  cout<<s.numSquares(43)<<endl;
  return 0;
}