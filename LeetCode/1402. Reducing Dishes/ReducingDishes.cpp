#include <queue>

using namespace std;

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
      priority_queue<int,vector<int>,greater<>> pqPos;
      priority_queue<int,vector<int>,less<>> pqNeg;
      for(int i = 0 ; i < satisfaction.size() ; i++){
        if(satisfaction[i] >= 0) {
          pqPos.push(satisfaction[i]);
        }else{
          pqNeg.push(satisfaction[i]);
        }
      }

      int posCumulative = 0;
      int posTotal = 0;
      int count = 1;
      while(pqPos.size()){
        posCumulative += pqPos.top();
        posTotal += (count++)*pqPos.top();
        pqPos.pop();
      }

      if(posTotal == 0) return 0;
      int res = posTotal;

      int tryTimes = pqNeg.size();
      int NegCumulative = 0;

      for(int i = 1; i <=tryTimes ; i++){
        priority_queue<int,vector<int>,less<>> dummy = pqNeg;
        for(int k = 0 ; k < i ; k++){
          NegCumulative += dummy.top();
          dummy.pop();
        }
        NegCumulative += posCumulative;
        res = max(res,posTotal+NegCumulative);
      }

      return res;
    }
};