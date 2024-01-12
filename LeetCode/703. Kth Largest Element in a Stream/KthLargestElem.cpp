#include <queue>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

class KthLargest {
private:
    priority_queue<int,vector<int>,greater<int>> pq2;
    int kthElem;
public:
    KthLargest(int k, vector<int>& nums) {
        kthElem = k;
        for(int i = 0 ; i < nums.size() ; i++){
          pq2.push(nums[i]);
          if(pq2.size()>k){
            pq2.pop();
          }
        }
    }

    int add(int val) {
      if(pq2.size()<kthElem){
        pq2.push(val);
        return pq2.top();
      }

      if(val>pq2.top()){
        pq2.pop();
        pq2.push(val);
      }
      return pq2.top();
    }
};

// class KthLargest {
// private:
//     priority_queue<int,vector<int>,less<int>> pq1;
//     //queue<int> q1;
//     priority_queue<int,vector<int>,greater<int>> pq2;
//     int kthElem;
//     vector<int> storage;
// public:
//     KthLargest(int k, vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         storage = nums;
//         kthElem = k;
//         for(int i = 0 ; i < nums.size() ; i++){
//           if(i<=nums.size()-kthElem){
//             pq1.push(nums[i]);
//           }else{
//             pq2.push(nums[i]);
//           }
//         }
//     }

//     int add(int val) {
//       // cout<<"pq2.top(): "<<pq2.top()<<endl;
//       if(pq1.size()<=kthElem){
//         storage.push_back(val);
//         KthLargest(kthElem,storage);
//       }

//       if(val>=pq2.top()){
//         pq1.push(pq2.top());
//         pq2.pop();
//         pq2.push(val);
//       }else if(val<pq2.top()){
//         pq1.push(val);
//       }
        
//       return pq1.top();
//     }
// };

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */