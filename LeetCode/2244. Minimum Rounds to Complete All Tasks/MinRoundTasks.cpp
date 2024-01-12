#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int Answer(vector<int>& tasks) {
        unordered_map<int,int> mp;
        for(int i=0;i<tasks.size();i++){
            mp[tasks[i]]++;
        }
        
        int output=0;
        
        for (auto freq : mp){
            if(freq.second==1)
                return -1;
            if(freq.second%3==0){
                output += freq.second/3;
            }
            else{
                output += freq.second/3 + 1;
            }
        }
        return output;
    }

    int minimumRounds(vector<int>& tasks) {
      int res = 0;
      vector<int> countVect;

      sort(tasks.begin(),tasks.end());
      int currentLevel = tasks[0] , currentValue = 0;
      for(int i : tasks){
        if(i!=currentLevel){
          currentLevel = i;
          countVect.push_back(currentValue);
          currentValue = 0;
        }
          currentValue++;
      }
      countVect.push_back(currentValue);
      int maxCount = *max_element(countVect.begin(),countVect.end());
      vector<int> minRoundVect(maxCount+1,0);
      //vector<int> minRoundVect(maxCount+1,1);

      // for(int i = 4 ; i <= maxCount ; i++){
      //     minRoundVect[i] = min(minRoundVect[i-2]+1,minRoundVect[i-3]+1);
      // } 

      for(int i = 0 ; i <= maxCount ; i++){
        if(i<4){
          minRoundVect[i] = 1;
        }else if (i==4){
          minRoundVect[i] = 2;
        }else{
          minRoundVect[i] = min(minRoundVect[i-2]+1,minRoundVect[i-3]+1);
        }
        
      }

      for(int i : countVect){
        if(i<=1) return -1;
        res += minRoundVect[i];
      }
      return res;
    }

    int minimumRoundsTest1(vector<int>& tasks) {
      int res = 0;
      vector<int> countVect;
      unordered_map<int,int> diffToCount;

      for(int i : tasks){
        diffToCount[i]++;
      }

      for(auto k: diffToCount){
        countVect.push_back(k.second);
      }
  
      int maxCount = *max_element(countVect.begin(),countVect.end());
      vector<int> minRoundVect(maxCount+1,0);
 
      for(int i = 0 ; i <= maxCount ; i++){
        if(i<4){
          minRoundVect[i] = 1;
        }else if (i==4){
          minRoundVect[i] = 2;
        }else{
          minRoundVect[i] = min(minRoundVect[i-2]+1,minRoundVect[i-3]+1);
        }
        
      } 

      for(int i : countVect){
        if(i<=1) return -1;
        res += minRoundVect[i];
      }
      return res;
    }
 

    int minimumRoundsTest2(vector<int>& tasks) {
      int res = 0;
      vector<int> countVect;
      unordered_map<int,int> diffToCount;

      // for(int i : tasks){
      //   diffToCount[i]++;
      // }

      // for(auto k: diffToCount){
      //   countVect.push_back(k.second);
      // }
      sort(tasks.begin(),tasks.end());
      int currentLevel = tasks[0] , currentValue = 0;
      for(int i : tasks){
        if(i!=currentLevel){
          currentLevel = i;
          //cout<<"currentValue"<<currentValue<<endl;
          countVect.push_back(currentValue);
          currentValue = 0;
        }
          currentValue++;
      }
      countVect.push_back(currentValue);
      int maxCount = *max_element(countVect.begin(),countVect.end());
      vector<int> minRoundVect(maxCount+1,0);
      // minRoundVect[0]=-1;
      // minRoundVect[1]=-1;
      // minRoundVect[2]=1;
      // minRoundVect[3]=1;
      // minRoundVect[4]=2;
      for(int i = 0 ; i <= maxCount ; i++){
        if(i<4){
          minRoundVect[i] = 1;
        }else if (i==4){
          minRoundVect[i] = 2;
        }else{
          minRoundVect[i] = min(minRoundVect[i-2]+1,minRoundVect[i-3]+1);
        }
        
      } 

      // for(int i : countVect){
      //   cout<<"out: "<<i<<endl;
      // }

      // for(auto k : diffToCount){
      //   int currCount = k.second;
      //   cout<<"currCount: "<<currCount<<endl;
      //   if(currCount<=1){
      //     return -1;
      //   }
      //   res += minRoundVect[currCount];
      // }

      for(int i : countVect){
        //cout<<i<<endl;
        if(i<=1) return -1;
        res += minRoundVect[i];
      }
      return res;
    }
};

int main(){
  Solution s;
  vector<int> tasks = {2,3,3};
  cout<<s.minimumRounds(tasks)<<endl;
  return 0;
}