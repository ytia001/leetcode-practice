#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
 
     vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int ptr = 0;
        sort(nums1.begin(),nums1.end());
        priority_queue<int,vector<int>,greater<int>> pq(nums2.begin(),nums2.end());
        while(ptr<nums1.size() && !pq.empty()){
          cout<<pq.top()<<"---"<<nums1[ptr]<<endl;
          if(pq.top()==nums1[ptr]){
            ptr++;
            res.push_back(pq.top());
            pq.pop();
          }else if (pq.top()>nums1[ptr]){
            ptr++;
          }else{
            pq.pop();
          }
        }

        return res;
    }

    vector<int> intersectTest1(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int,int> countMap;
        for(int i : nums1){
          countMap[i]++;
        }
        for(int i : nums2){
          if(countMap.count(i) && countMap[i]>0){
            countMap[i]--;
            res.push_back(i);
          }
        }

        return res;
    }

    //   vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    //     vector<int> res;
    //     for(int i : nums2){
    //       auto it = find(nums1.begin(),nums1.end(),i);
    //       if(it!=nums1.end()){
    //         res.push_back(i);
    //         nums1.erase(it);
    //       }
    //     }

    //     return res;
    // }
};

int main(){
  Solution s;
  vector<int> nums1 = {1,2};
  vector<int> nums2 = {1,1};
  vector<int> result = s.intersect(nums1,nums2);
  for(int i: result){
    cout<<i<<endl;
  }
  return 0;
}