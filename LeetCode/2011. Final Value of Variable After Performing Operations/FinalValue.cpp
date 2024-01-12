#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
      int res = 0;
      for(auto s : operations){
        if(s=="++X"||s=="X++"){
          res++;
        }else{
          res--;
        }
      }
      return res;
    }
};