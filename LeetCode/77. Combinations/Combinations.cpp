#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;

    void search (int n , int k , int val , vector<int>& placeHolder){
      
      if(placeHolder.size()==k){
        res.push_back(placeHolder);
        return;
      }

      if(val>n){
        return;
      }

      for(int i = val ; i <= n ; i++){
        placeHolder.push_back(i);
        search(n,k,i+1,placeHolder);
        placeHolder.pop_back();
      }
    }
    
    void search (int n , int k , int val , vector<int>& placeHolder){
      if(k==0){
        res.push_back(placeHolder);
        return;
      }
      
      if(val>n){
        return;
      }

      for(int i = val ; i < n ; i++){
        placeHolder.push_back(i);
        search(n,k-1,i+1,placeHolder);
        placeHolder.pop_back();
      }
    }


    vector<vector<int>> combine(int n, int k) {
      // vector<vector<int>> res;
      vector<int> placeHolder;
      search(n,k,1,placeHolder);

      return res;
    }
};