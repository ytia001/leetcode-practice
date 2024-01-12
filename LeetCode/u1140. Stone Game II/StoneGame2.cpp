#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

class Solution {
public:

    int stoneGameII(vector<int>& piles) {
      int res = 0;
      int size = piles.size();
      int totalStone = accumulate(piles.begin(),piles.end(),0);
      return res;
    }


    int stoneGameIITest(vector<int>& piles) {
        int res = 0;
        bool aliceTurn = true;
        int maxMove = 2;
        vector<int> resultantSum(piles.size());
        for(int i = 0; i<piles.size(); i++){
          resultantSum[i] = piles[i];
        }
        int ptr = 0;

        while(ptr<=piles.size()-1){

          if(aliceTurn){
            int newPtr = ptr;
            int toRes = 0;
            int newMaxMove = 0;
            int currentSmallest =INT_MAX;
            for(int i = 1 ; i <= maxMove ; i++){
              int bobMaxMove = 2*i; 
              int bobSum = resultantSum[newPtr+(i-1)+bobMaxMove] - resultantSum[newPtr+(i-1)];
              if(bobSum < currentSmallest){
                ptr = newPtr+i;
                currentSmallest = bobSum;
                toRes = resultantSum[newPtr+(i-1)];
                newMaxMove = bobMaxMove;
              }
            }
            res += toRes;
            maxMove = newMaxMove;
            aliceTurn = !aliceTurn;

          }else{
            int newPtr = ptr;
            int newMaxMove = 0;
            int currentSmallest =INT_MAX;
            for(int i = 1 ; i <= maxMove ; i++){
              int aliceMaxMove = 2*i; 
              int aliceSum = resultantSum[newPtr+(i-1)+aliceMaxMove] - resultantSum[newPtr+(i-1)];
              if(aliceSum < currentSmallest){
                ptr = newPtr+i;
                currentSmallest = aliceSum;
                newMaxMove = aliceMaxMove;
              }
            }
            maxMove = newMaxMove;
            aliceTurn = !aliceTurn;

          }
        }
      return res;
    }
};