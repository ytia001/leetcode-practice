#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:

      int coinChange(vector<int>& coins, int amount) {
        if(amount == 0 ) return 0;

        int smallestCoin = *min_element(coins.begin(),coins.end());
        vector<long long> container(amount+1,0);
        unordered_set<int> coinsSt(coins.begin(),coins.end());
        container[0] = 0;
        for(int i = smallestCoin ;  i <= amount ; i++ ){
          if(coinsSt.count(i)){
            container[i] = 1;
          }else{
            long long store = INT_MAX;
            for(int j = 0 ; j < coins.size() ; j++){
              int currentCoin = coins[j];
              if(currentCoin>i) break;
              if(container[i-currentCoin]==0){
                continue;
              }
              store = min(store,container[i-currentCoin]);
            }
            container[i] = store + 1;
          }
          cout<<"i: "<<i<<"container[i]: "<<container[i]<<endl;
        }
        
        if(container[amount]==-1) return -1;
        return container[amount];
    }


    // int coinChange(vector<int>& coins, int amount) {
    //     if(amount == 0 ) return 0;

    //     int smallestCoin = *min_element(coins.begin(),coins.end());
    //     vector<long long> container(amount+1,-1);
    //     unordered_set<int> coinsSt(coins.begin(),coins.end());
    //     container[0] = 0;
    //     for(int i = smallestCoin ;  i <= amount ; i++ ){
    //       if(coinsSt.count(i)){
    //         container[i] = 1;
    //       }else{
    //         long long store = INT_MAX;
    //         for(int j = 0 ; j < coins.size() ; j++){
    //           int currentCoin = coins[j];
    //           if(currentCoin>i) break;
    //           if(container[i-currentCoin]==-1){
    //             store = -2;
    //             break;
    //           }
    //           store = min(store,container[i-currentCoin]);
    //         }
    //         container[i] = store + 1;
    //       }
    //       cout<<"i: "<<i<<"container[i]: "<<container[i]<<endl;
    //     }
        
    //     if(container[amount]==-1) return -1;
    //     return container[amount];
    // }
};