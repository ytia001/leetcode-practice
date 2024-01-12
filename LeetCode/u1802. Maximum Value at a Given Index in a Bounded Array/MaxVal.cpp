#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:

    long long sum(int index, int value, int n){
      long long current = value;
      // if(index<0 || index>= n){
      //   return 0;
      // }
      // value = value<1? 1 : value-1;
      // current = value + sum()
      int start = index + 1;
      long long currentVal = value;
      while(start++<n){
        currentVal = currentVal==1? 1 : currentVal-1;
        current+= currentVal;
      }
      start = index-1;
      currentVal = value;
      while(start-->=0){
        currentVal = currentVal==1? 1 : currentVal-1;
        current+= currentVal;
      }
      return current;
    }

    int maxValue(int n, int index, int maxSum) {
        int res = 1;
        int maxVal = maxSum - (n-1);
        for(int i = maxVal ; i > 1 ; i--){
          if(sum(index,i,n)<=maxSum){
            // res = max(res,i);
            res = i;
            break;
          }
        }
        return res;
    }
};

int main(){

  Solution s;
  cout<<s.maxValue(3,0,815094800)<<endl;
  return 0;
}