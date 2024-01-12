#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:

    
    vector<vector<int>> res;

    void search(vector<int>& candidates,vector<int> combo, int remainder , int index){
      if(index>candidates.size()-1 || remainder < 0){
        return;
      }

      search(candidates,combo,remainder,index+1);

      combo.push_back(candidates[index]);
      if(remainder - candidates[index] == 0){
        res.push_back(combo);
        return;
      }

      search(candidates,combo,remainder-candidates[index],index+1);
      
    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      vector<int> combo;
      search(candidates,combo,target,0);
      return res;
    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<set<vector<int>>> container(target+1);
        // for(int i : candidates){
        //   if(i <= target && container[i].empty()){
        //     container[i].insert(vector<int>(i));
        //   }
        // }

        for(int i = 0 ; i < candidates.size() ; i++){
          int candidate = candidates[i];
          if(candidate > target) continue;
          for(int j = candidate -1 ; j>=0 ; j--){
            if(j+candidate <= target && !container[j].empty()){
              for(auto& k : container[j]){
                vector<int> currentVect = k;
                currentVect.push_back(candidate);
                container[j+candidate].insert(currentVect);
              }
            }
          }
        }

        return vector<vector<int>> (container[target].begin(),container[target].end());  
    }

  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> container(target+1);
    for(int i : candidates){
      if(container[i].empty() && i <= target){
        container[i].push_back({i});
      }
    }

    for(int i = 0 ; i < candidates.size() ; i++){
      int candidate = candidates[i];
      if(candidate > target) continue;
      for(int j = candidate -1 ; j>0 ; j--){
        if(j+candidate <= target && !container[j].empty()){
          for(auto& k : container[j]){
            vector<int> currentVect = {k};
            currentVect.push_back(candidate);
            container[j+candidate] = currentVect;
          }
        }
      }
    }

    return vector<vector<int>> (container[target].begin(),container[target].end());
  }

  // vector<vector<int>> res;

  // void search(vector<int>& candidates,vector<int> combo, int remainder , int index){
  //   if(index>candidates.size()-1 || remainder < 0){
  //     return;
  //   }
  //   if(remainder == 0){
  //     res.push_back(combo);
  //   }

  //   for(int i = index ; i < candidates.size() ; i++){
  //     combo.push_back(candidates[i]);
  //     search(candidates,combo,remainder-candidates[i],index+1);
  //     combo.pop_back();
  //   }
  // }


  // vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
  //   vector<int> combo;
  //   //sort(candidates.begin(),candidates.end());
  //   search(candidates,combo,target,0);
  //   return res;
  // }
};