#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int res = 0;
        unordered_map<int,pair<int,int>> map;

        for(int i = 0; i < nums1.size() ; i++){
          for(int j = 0 ; j < nums2.size();j++){
            map[nums1[i]+nums2[j]].first++;
            map[-(nums3[i]+nums4[j])].second++;
          }
        }

        for(auto k : map){
          // if(k.second.first != 0 && k.second.second != 0 ){
          //   res += (k.second.first*k.second.second);
          // }
          res += (k.second.first*k.second.second);
        }

        return res;
    }

    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int res = 0;
        unordered_map<int,int> map1;
        //unordered_set<int> container2;

        for(int i = 0; i < nums1.size() ; i++){
          for(int j = 0 ; j < nums2.size();j++){
            map1[nums1[i]+nums2[j]]++;
          }
        }

        for(int i = 0; i < nums3.size() ; i++){
          for(int j = 0 ; j < nums4.size();j++){
            if(map1[-(nums3[i]+nums4[j])]>0){
              res += map1[-(nums3[i]+nums4[j])];
              //map1[-(nums3[i]+nums4[j])]--;
            }
          }
        }

        return res;
    }
};