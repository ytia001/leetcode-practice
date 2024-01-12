#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:

     int climbStairs(int n) {
      if(n==0 || n==1) return 1;
      vector<int> container(n+1,1);
      for(int i = 2 ; i<=n ; i++){
        container[i] = container[i-1] + container[i-2];
      }
      return container[n];
    }


    int climbStairs(int n) {
      if(n==0 || n==1) return 1;
      return climbStairs(n-1) + climbStairs(n-2);  
    }
};