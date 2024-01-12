#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <unordered_set>

using namespace std;

class Solution {
public:

    int Answer(int N, vector<vector<int>>& trust) {
        vector<int> count(N + 1, 0);
        for (auto& t : trust)
            count[t[0]]--, count[t[1]]++;
        for (int i = 1; i <= N; ++i) {
            if (count[i] == N - 1) return i;
        }
        return -1;
    }
    
    int findJudge(int n, vector<vector<int>>& trust) {
      vector<int> noTrustVect(n+1,1);
      vector<int> numTrustVect(n+1,0);
      noTrustVect[0] = 0;
      for(auto k : trust){
        noTrustVect[k[0]] = 0;
        numTrustVect[k[1]]++;
      }
      //cout<<accumulate(noTrustVect.begin(),noTrustVect.end(),0)<<endl;
      if(accumulate(noTrustVect.begin(),noTrustVect.end(),0)!=1){
        return -1;
      }else{
        int judgeIdx = find(noTrustVect.begin(),noTrustVect.end(),1)-noTrustVect.begin();
        if(numTrustVect[judgeIdx]==(n-1)){
          return judgeIdx;
        }
        return -1;
      }
    }

    // int findJudge(int n, vector<vector<int>>& trust) {
    //   if(n==1) return 1;
    //   unordered_map<int,int> trustMap;
      
    //   for(auto i : trust){
    //     trustMap.erase(i[0]);
    //     trustMap[i[1]]++;
    //   }

    //   if(trustMap.size()!=1 || trustMap.begin()->second!=(n-1)){
    //     return -1;
    //   }else{
    //     return trustMap.begin()->first;
    //   }
    // }

};

int main(){
  Solution s;
  vector<vector<int>> trust = {{1,2}};
  //[[1,2]],[[1,3],[2,3]],[[1,3],[2,3],[3,1]],[[1,2],[2,3]],[],[[1,2],[2,1]],[]
  //2,3,3,3,1,2,2
  cout<<s.findJudge(2,trust)<<endl;
  return 0; 
}