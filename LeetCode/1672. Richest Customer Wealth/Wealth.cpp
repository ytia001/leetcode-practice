#include<vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int res = 0;
        for(int i = 0 ; i < accounts.size() ; i ++){
          int currentWealth = 0;
          for(int j = 0 ; j < accounts[i].size() ; j++){
            currentWealth += accounts[i][j];
          }
          res = max(res,currentWealth);
        }
        return res;
    }
};

int main(){
  Solution s;
  vector<vector<int>> accounts = {{1,5},{7,3},{3,5}};
  cout<<s.maximumWealth(accounts)<<endl;
  return 0;
}