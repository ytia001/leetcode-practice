#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      vector<set<vector<int>>> container(target+1);
      sort(candidates.begin(),candidates.end());
      for(int i = 1 ; i <= target ; i++){
        for(int& num : candidates){
          if(num > i) break;
          if((i-num)!=0 && container[i-num].empty()) continue;
          //cout<<"i: "<<i<<"  "<<container[i-num].size()<<endl;
          if((i-num)==0){
            container[i].insert({num});
          }
          else{
            for(auto& k : container[i-num]){
                vector<int> toAdd = k;
                toAdd.push_back(num);
                sort(toAdd.begin(),toAdd.end());
                container[i].insert(toAdd);
             }
          }
        }
      }

      // set<vector<int>> stRes;
      // for(auto& k:container[target]){
      //   vector<int> toAdd = k;
      //   sort(toAdd.begin(),toAdd.end());
      //   stRes.insert(toAdd);
      // }

      vector<vector<int>> res(container[target].begin(),container[target].end());
      return res;
    }
};

int main(){

  Solution s;
  vector<int> candidates = {2,3,6,7};
  vector<vector<int>> res = s.combinationSum(candidates,8);

  return 0;
}