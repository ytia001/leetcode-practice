#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:

    int Answer(vector<int>& a) {
        size_t maxsize = 0;
        for (int i = 0; i < a.size(); i++) {
            size_t size = 0;
            for (int k = i; a[k] >= 0; size++) {
                int ak = a[k];
                a[k] = -1; // mark a[k] as visited;
                k = ak;
            }
            maxsize = max(maxsize, size);
        }

        return maxsize;
    }
   
    int arrayNesting(vector<int>& nums) {
      int res = 0;
      int currCount = 0;
      unordered_set<int> idxSet;

      for(int i = 0 ; i < nums.size() ; i++){
        if(i==nums[i]){
          res = 1;
          continue;
        }
        idxSet.insert(i);
      }

      if(idxSet.empty()){
        return res;
      }
      
      auto start = idxSet.begin();
      int curIdx = *start;

      while(!idxSet.empty()){
        int curVal = nums[curIdx];

        // if(curIdx == curVal){
        //   res = max(res,1);
        // }

        if(idxSet.count(curVal)){
          currCount ++;
          idxSet.erase(curIdx);
          curIdx = curVal;
          
        }else{
          currCount++;
          idxSet.erase(curIdx);
          res = max(res,currCount);
          currCount = 0;

          if(!idxSet.empty()){
            start = idxSet.begin();
            curIdx = *start;
          }else{
            break;
          }
        }
      }


      return res;
    }

     int arrayNestingTest(vector<int>& nums) {
      unordered_map<int,int> idxToNum;
      unordered_set<int> s;
      int res = 0;

      for(int i = 0 ; i < nums.size() ; i++){
        if(i==nums[i]){
          res = 1;
          continue;
        }
        idxToNum[i]=nums[i];
      }

      if(idxToNum.empty()){
         return res;
      }
      
      auto start = idxToNum.begin();
      int currIdx = start ->first;
      int currNum = start -> second;

      while(!idxToNum.empty()){
        //currNum = idxToNum[currIdx];

        if(idxToNum.find(currNum)!=idxToNum.end()){
          s.insert(currNum);
          idxToNum.erase(currIdx);
          currIdx = currNum;
          currNum = idxToNum[currIdx];
        }else{

          s.insert(currNum);
          idxToNum.erase(currIdx);

          int currSize = s.size();
          res = max(res,currSize);
          s.clear();

          if(!idxToNum.empty()){
            auto start = idxToNum.begin();
            currIdx = start -> first;
            currNum = start -> second;
          }else{
            break;
          }
          
        }
      }

      return res;
    }

};

int main(){

  Solution s;
  //vector<int> test = {5,4,0,3,1,6,2};
  vector<int> test = {0,1,2};
  cout<<s.arrayNestingTest(test)<<endl;
  return 0;
}