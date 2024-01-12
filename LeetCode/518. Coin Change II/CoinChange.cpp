#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:

    int change(int amount, vector<int>& coins) {
      unordered_set<int> coinSt(coins.begin(),coins.end());
      unordered_set<int> his
      vector<int> container(amount+1,0);
      container[0] = 1;

      for(int i = 1 ; i < container.size() ; i++){

      }
    }


    // int res = 0;

    // void search(vector<int>& coins, int index, int current, int amount){
    //   if(current > amount){
    //     return;
    //   }
      
    //   if (current == amount){
    //     res++;
    //     return;
    //   }

    //   for(int i = index ; i < coins.size() ; i++){
    //     search(coins,i,current+coins[i],amount);
    //   }
    // }

    // int change(int amount, vector<int>& coins) {
    //   search(coins,0,0,amount);
    //   return res;
    // } 
};