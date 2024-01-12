#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:

    vector<int> productExceptSelf(vector<int>& nums) {
        
    }

    // vector<int> productExceptSelf(vector<int>& nums) {
    //  vector<int> res(nums.size(),0);
    //  if(nums.size()%2) {
    //   int sum = 1;
    //   int idx = -1;
    //   for(int i = 0 ; i < nums.size() ; i++){
    //     if(i*2==nums.size()-1){
    //       idx = i;
    //       continue;
    //     }
    //     sum *= nums[i];
    //   }
    //   res[idx] = sum;
    //  }

    //  int l = 0 , r = nums.size()-1;
    // //  stack<int> st1,st2;
    //  stack<int> st1;
    //  queue<int> q1;
    //  int curVal = 1;

    //  for(int i = 0 ; i < nums.size() ; i++){
    //   st1.push(nums[i]);
    //   if(st1.size()==(nums.size()-1)){
    //     res[r--] = curVal*st1.top();
    //     q1.push(st1.top());
    //     st1.pop();
    //     continue;
    //   }
    //   curVal *= st1.top();
    //  }

    //  if(r<0) return res;

    //  while(st1.size()){
    //   q1.push(st1.top());
    //   st1.pop();
    //  }

    //  curVal = 1;
    //  int count = 0;
    //  while(!q1.empty()){
    //   int current = q1.front();
    //   q1.pop();
    //   count ++;
    //   if(count==(nums.size()-1)){
    //     res[l++] = curVal * current;
    //     count--;
    //     continue;
    //   }
    //   curVal *= current;
    //  }
    //  return res;
    // }
};