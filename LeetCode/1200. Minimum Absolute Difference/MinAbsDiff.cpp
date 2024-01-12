#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
       vector<vector<int>> res;
       sort(arr.begin(),arr.end());
       int min = INT_MAX;
       for ( int i = 1 ; i < arr.size() ; i++){
        int current = arr[i]-arr[i-1];
        if(current<min){
            res.clear();
            min = current;
            res.push_back({arr[i-1],arr[i]});
          }else if(current==min){
            res.push_back({arr[i-1],arr[i]});
          }
       }
       return res;
    }


    vector<vector<int>> minimumAbsDifferenceTest(vector<int>& arr) {
       vector<vector<int>> res;
       int min = INT_MAX;
       sort(arr.begin(),arr.end());
       for ( int l = 0 ; l < arr.size()-1 ; l++){
          int r = arr.size()-1;
          while(l<r){
            int sum = arr[r] - arr[l];
            // cout<<"arr[l]: "<<arr[l]<<" arr[r]: "<<arr[r]<<endl;
            // cout<<"sum: "<<sum<<endl;
            if(sum<min){
              res.clear();
              min = sum;
              res.push_back({arr[l],arr[r]});
            }else if(sum==min){
              res.push_back({arr[l],arr[r]});
            }
              r--;
          }
       }
       return res;
    }
};

int main(){
  Solution s;
  vector<int> test ={4,2,1,3};
  vector<vector<int>> res = s.minimumAbsDifference(test);
  for(auto i : res){
    for(int j: i){
      cout<<j<<" ";
    }
    cout<<endl;
  }
  return 0;
}