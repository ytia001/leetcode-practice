#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    // bool check(int value,int idx, unordered_map<int,vector<int>> elemToIdx){
    //   for(auto i : elemToIdx[value]){
    //     if(i>=idx) return true;
    //   }
    //   return false;
    // }

    // int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
    //     int total = 0;
    //     vector<int> minVect, maxVect;
    //     (nums1.size()<=nums2.size())? minVect = nums1 , maxVect = nums2 : maxVect = nums1 , minVect = nums2;
    //     int ptrMin = 0,ptrMax = 0;
    //     while(ptrMax<=(maxVect.size()-1)){
    //       if(minVect[ptrMin] == maxVect[ptrMax]){
    //         total ++;
    //         ptrMin++;
    //         ptrMax++;
    //       }
    //        ptrMax++;
    //     }
        
    // }

      int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int total = 0;
        queue<vector<int>> container,copy;
        unordered_map<int,vector<int>> elemToIdx;
        vector<int> minVect, maxVect;

        (nums1.size()<=nums2.size())? (minVect = nums1 , maxVect = nums2) : (maxVect = nums1 , minVect = nums2);

        for (int i = 0 ; i < maxVect.size() ; i ++){
          elemToIdx[maxVect[i]].push_back(i);
        }

        // for(auto i : elemToIdx){
        //     cout<<i.first<<endl;
        //   for(auto k: i.second){
        //     cout<<k<<endl;
        //   }
        //   cout<<"----"<<endl;
        // }

        // for(int i : minVect){
        //   cout << i <<endl;
        // }


        for(int i : minVect){
          copy = container;
          while(!copy.empty()){
            vector<int> currVect = copy.front();
            copy.pop();
            container.pop();
            int currVectLastElem = currVect[currVect.size()-1];
            //cout<<"currVectLastElem"<<currVectLastElem<<endl;
            if(currVectLastElem == (maxVect.size()-1) ){
              // cout<<currQueue.size()<<endl;
              cout<<"contents: ";
              for(auto i : currVect){
                cout<<i<<" ";
             }
              cout<<" "<<endl;
              if(currVect.size()>total){
                total = currVect.size();
              }
              continue;
            }
            for(auto k : elemToIdx[i]){
              if(currVectLastElem<k){
                //cout<<"i: "<<i<<" currLastElem: "<<currVectLastElem<<" k: "<<k<<endl;
                currVect.push_back(k);
                break;
              }
            }
            container.push(currVect);
            // cout<<"contents: ";
            // for(auto i : currVect){
            //   cout<<i<<" ";
            // }
            // cout<<" "<<endl;
          }
          // cout << i <<endl;
          //cout<<elemToIdx[i][0]<<endl;

          if(find(maxVect.begin(),maxVect.end(),i) != maxVect.end()){
            container.push({elemToIdx[i][0]});
          }
          
        }

        while(!container.empty()){
           vector<int> currVect = container.front();
           cout<<"contents: ";
              for(auto i : currVect){
                cout<<i<<" ";
             }
              cout<<" "<<endl;
          container.pop();
          if(currVect.size()>total){
            total = currVect.size();
          }
        }
        return total;
    }
};

int main(){

  vector<int> main1 = {4,1,5,2,1,1,1,5,3,1,1,1,2,3,1,4,3,5,5,3,1,2,3,2,4,1,1,1,5,3};
  vector<int> main2 = {3,1,4,1,1,3,5,1,2,2};
  Solution s;
  cout<<s.maxUncrossedLines(main1,main2)<<endl;
  return 0;
}