#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:

    int candy(vector<int>& ratings) {
      int res = 0;
      int size = ratings.size();
      vector<int> candyVect(size,1);

      for(int i = 1; i < ratings.size();i++){
        if(ratings[i] > ratings[i-1]){
          candyVect[i] = candyVect[i-1] + 1;
        }
      }

      for(int i = ratings.size()-2 ; i >= 0 ;i--){
        // if(ratings[i] > ratings[i+1] && candyVect[i] <= candyVect[i+1]){
        //   candyVect[i] = candyVect[i+1] + 1;
        // }
        if(ratings[i] > ratings[i+1] ){
          candyVect[i] = max(candyVect[i],candyVect[i+1] + 1);
        }
      }

      return accumulate(candyVect.begin(),candyVect.end(),0);
    }


    // int candy(vector<int>& ratings) {
    //   int res = 0;
    //   int size = ratings.size();
    //   vector<int> candyVect(size,1);

    //   for(int i = 0 ; i < ratings.size() ; i++){
    //     if( i == 0 ){
    //       candyVect[i] = ratings[i] > ratings[i+1] ? candyVect[i]+1 : candyVect[i];
    //     }
    //     else if ( i== ratings.size()-1){
    //       candyVect[i] = ratings[i] > ratings[i-1] ? candyVect[i]+1 : candyVect[i];
    //     }else{
    //       // int maxVal = max({ratings[i-1],ratings[i],ratings[i+1]});
    //       // int minVal = min({ratings[i-1],ratings[i],ratings[i+1]});
    //       if(ratings[i])
    //     }
    //   }


    // }
};