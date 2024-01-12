#include <string>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:

    // TLE
    int minExtraChar(string s, vector<string>& dictionary) {
      int size = s.size();
      int res = INT_MAX;
      queue<pair<int,int>> q;
      for(int i = 0 ; i < dictionary.size() ; i++){
        auto pos = s.find(dictionary[i]);
        if(pos != string::npos){
          cout<<"startPos: "<<pos+dictionary[i].size()<<" extra:"<<pos<<endl;
          q.push({pos+dictionary[i].size(),pos});
        }
      }

      while(!q.empty()){
        auto[startPos,extra] = q.front();
        q.pop();
        if(startPos >= s.size()){
          res = min(res,extra);
          continue;
        }else{
          res = min(res,extra + size-startPos);
        }

        for(int i = 0 ; i < dictionary.size() ; i++){
          auto pos = s.find(dictionary[i],startPos);
          if(pos != string::npos){
            cout<<"startPos: "<<pos+dictionary[i].size()<<" extra:"<<extra + (pos-startPos)<<endl;
            q.push({pos+dictionary[i].size(),extra + (pos-startPos)});
          }
        }
        
      }

      return res;

    }


    // int minExtraChar(string s, vector<string>& dictionary) {
    //   int size = s.size();
    //   vector<int> dp(size + 1,0);
    //   for(int i = 1; i < size + 1 ; i++){
    //     for(int j = i ; j >=0 ; j--){
          
    //     }
    //   }

    // }
};