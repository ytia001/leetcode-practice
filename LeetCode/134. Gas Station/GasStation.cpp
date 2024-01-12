#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
      // int res = -1;
      // int netReduction = 0;
      int size = gas.size();
      // for(int i = 0 ; i < gas.size() ; i++){
      //   netReduction += (gas[i] - cost[i]);
      // }

      // if(netReduction < 0) return res;

      int current = 0, l = 0;
      for(int i = 0 ; i < 2 * size ; i++){
        current += (gas[i%size]-cost[i%size]);
        while(current < 0 && l <= i){
          current -= (gas[l%size]-cost[l%size]);
          l++;
        }
        if(i-l+1 == size){
            return l;
        }
      }

      return -1; 
    }

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
      int res = -1;
      int netReduction = 0;
      int size = gas.size();
      for(int i = 0 ; i < gas.size() ; i++){
        netReduction += (gas[i] - cost[i]);
      }

      if(netReduction < 0) return res;

      int current = 0, l = 0;
      for(int i = 0 ; i < 2 * size ; i++){
        current += (gas[i%size]-cost[i%size]);
        //cout<<"current: "<<current<<" l: "<<l<<" i: "<<i<<endl;
        while(current < 0 && l <= i){
          current -= (gas[l%size]-cost[l%size]);
          l++;
        }
        if(i-l+1 == size){
          if(current == netReduction){
            return l;
          }else{
            current -= (gas[l%size]-cost[l%size]);
            l++;
          }
        }
      }

      return res; 
    }
};