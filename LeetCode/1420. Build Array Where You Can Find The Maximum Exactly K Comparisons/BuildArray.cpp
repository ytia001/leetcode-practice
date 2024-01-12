#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int res;
    int arraySize;
    int values;
    int targetCost;

    void search(int idx , int i, int cost, int cumulative){
      if(i == values && cost < targetCost ) return;
      if(idx > arraySize - 1) return;
      cout<<"idx: "<<idx<<" i: "<<i<<" cost: "<<cost<<" cumulative:"<<cumulative<<endl;
      // if(cost == targetCost && i == values ){
      //   cout<<"idx: "<<idx<<" i: "<<i<<" cost: "<<cost<<" cumulative:"<<cumulative<<endl;
      //   res +=  pow(values,arraySize-1-idx) + cumulative;
      //   //res += (cumulative!=1 ? cumulative : 0);
      //   return;
      // }
      if(cost == targetCost && i == values ){
        cout<<"idx: "<<idx<<" i: "<<i<<" cost: "<<cost<<" cumulative:"<<cumulative<<endl;
        res +=  cumulative * (arraySize-1-idx)*i;
        //res += (cumulative!=1 ? cumulative : 0);
        return;
      }
      else if(cost == targetCost && idx == arraySize - 1){
        cout<<"idx: "<<idx<<" i: "<<i<<" cost: "<<cost<<" cumulative:"<<cumulative<<endl;
        res += cumulative;
        //res +=  i + (cumulative!=1 ? cumulative : 0);
      }

      search(idx+1,i,cost,cumulative*i);
      search(idx+1,i+1,cost+1,cumulative);
    }

    int numOfArrays(int n, int m, int k) {
      res = 0;
      arraySize = n , values = m , targetCost = k;
      for(int i = 1 ; i <= m ; i ++){
        search(0,i,1,1);
      }  

      return res;
    }
};

class Solution {
public:

    int res;
    int arraySize;
    int values;
    int targetCost;

    void search(int idx , int i, int cost, int cumulative){
      if(i == values && cost < targetCost ) return;
      if(idx > arraySize - 1) return;
      if(cost == targetCost && i == values ){
        //cout<<"idx: "<<idx<<" i: "<<i<<" cost: "<<cost<<endl;
        res+= pow(values,arraySize-1-idx) + cumulative!=1 ? cumulative : 0;
        return;
      }
      else if(cost == targetCost && idx == arraySize - 1){
        //cout<<"idx: "<<idx<<" i: "<<i<<" cost: "<<cost<<endl;
        res += i + cumulative!=1 ? cumulative : 0;
      }

      search(idx+1,i,cost,cumulative*i);
      search(idx+1,i+1,cost+1,cumulative);
    }

    int numOfArrays(int n, int m, int k) {
      res = 0;
      arraySize = n , values = m , targetCost = k;
      for(int i = 1 ; i <= m ; i ++){
        search(0,i,1,1);
      }  

      return res;
    }
};