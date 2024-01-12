#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int> pairs(spells.size(),0);
        for(int i = 0 ; i<spells.size(); i++){
          pairs[i] = threshold((long long)spells[i],potions,success);
        }
      return pairs;
    }

    int threshold(long long spellStrength,vector<int>& potions,long long success){
      int l = 0;
      int r = potions.size()-1;
      int reject = 0 ;
      long long currStrength = 0;
      while(l<r){
        int mid = l + (r-l)/2 ;
        currStrength = spellStrength*potions[mid];
        if(currStrength >= success){
          r = mid;
        }else{
          l = mid + 1;
        }
      }
      currStrength = spellStrength*potions[l] >= success;
      return (currStrength)? (potions.size())-l : 0;
    }

   vector<int> answer(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        vector<int> pairs(n, 0);
        sort(potions.begin(), potions.end());
        for (int i = 0; i < n; i++) {
            int spell = spells[i];
            int left = 0;
            int right = m - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                long long product = (long long)spell * (long long)potions[mid];
                if (product >= success) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            pairs[i] = m - left;
        }
        return pairs;
    }
    // int threshold(long long spellStrength,vector<int>& potions,long long success){
    //   int l = 0;
    //   int r = potions.size()-1;
    //   int reject = 0 ;
    //   long long currStrength = 0;
    //   while(l<r){
    //     int mid = l + (r-l)/2 ;
    //     // cout<<"mid:"<<floor((r-l+1)/2)<<endl;
    //     //currStrength = spellStrength*potions[mid];
    //     if(spellStrength*potions[mid] >= success){
    //       r = mid;
    //     }else{
    //       l = mid + 1;
    //     }
    //   }
    //   // l==r
    //   // either index at l * spellstrength >= sucess
    //   // or index at l * spellstrength < sucess 
    //    //cout<<"l: "<<l <<"r:"<<r<<endl;
    //   //currStrength = spellStrength*potions[l];
    //   if(spellStrength*potions[l] >= success){
    //     reject = l;
    //   }else{
    //     reject = potions.size();
    //   }
    //   return (potions.size())-reject;
    // }



};

int main(){
  Solution s;
  vector<int> spells = {38,11};
  vector<int> potions = {3,20}; 
  int success = 1065; 
  vector<int> result = s.successfulPairs(spells,potions,success);
  for(int i :result){
    cout<<i<<endl;
  }
  // cout<<5/2<<endl;
  return 0;
}