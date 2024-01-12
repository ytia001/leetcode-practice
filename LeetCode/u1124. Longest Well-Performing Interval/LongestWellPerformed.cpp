#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestWPI(vector<int>& hours) {
      int size = hours.size();
      int countOne = 0;
      int countZero = 0;
      int res = 0;
      int window = 0;
      for(int i = 0 ; i < size ; i++){
        if(hours[i]>8){
          countOne ++;
          // hours[i] = 1;
        }else{
          countZero ++;
          //hours[i] = 0; 
        }
      }

      if(countOne == 0){
        return 0;
      }else if(countZero == 0 || countOne > countZero){
        return size;
      }else{

      window = countOne + (countOne-1);
      res = 1;
      // countOne = 0;
      // countZero = 0;

      while(window >0){
        for(int i = 0,countOne = 0, countZero = 0 ; i< size ;i++ ){
          if(i+1<=window){
            //if(hours[i]==1) countOne++;
            hours[i]>8 ? countOne++ : countZero++;
            continue;
          }
          if(countOne>countZero) res = max(res,countOne);
          // if(hours[i-window]==1) countOne--;
          // if(hours[i]==1) countOne++;

          hours[i-window]>8 ? countOne-- : countZero--; 
          hours[i]>8 ? countOne++ : countZero++;
        }
        if(countOne>countZero) res = max(res,countOne);
        if(res>1) break;
        window--;
      }
    }
      return res+(res-1);
    }
};