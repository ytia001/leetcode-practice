#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
     int numRescueBoats(vector<int>& people, int limit) {
      vector<int> count(limit+1,0);
      int total = 0;
      for(int i : people){
        count[i]++;
      }
      for(int i = 1 ; i < count.size() ; i++){
        int right = limit - i;
        while(count[i]!=0 && i<=right){
          if(i==right && count[i]==1){
            break;
          }
          if(count[right]>=1){
              total ++;
              count[i]--;
              count[right]--;
          }else{
              right--;
          }  
        }
      }

      for (int i : count){
        total += i;
      }

      
      return total;
    }

    int answer(vector<int>& people, int limit) {
        int boatCount = 0;
        sort(people.begin(), people.end());
        
        int left = 0;
        int right = people.size() - 1;
        
        while(left <= right){
            int sum = people[left] + people[right];
            if(sum <= limit){
                boatCount++;
                left++;
                right--;
            }
            else{
                boatCount++;
                right--;
            }
        }
        return boatCount;
    }
    // int numRescueBoats(vector<int>& people, int limit) {
    //     vector<int> leftover(limit,0);
    //     //int total = 0;
    //     for(int i : people){
    //       // cout<<"i:"<<i<<" limit-i:"<<limit-i<<endl;
    //       if(i==limit){
    //         leftover[0]++;
    //         continue;
    //       }
    //       if(leftover[i]){
    //         leftover[i]--;
    //         leftover[0]++;
    //       }else{
    //         leftover[limit-i]++;
    //       }
    //     }
    //     //cout<<"dsff"<<endl;
    //     // for(int i: leftover){
    //     //   total += i;
    //     // }
        
    //     return accumulate(leftover.begin(),leftover.end(),0);
    // }

};

int main(){
  Solution s;
  vector<int> test = {3,2,2,1};
  int limit = 3;
  int result = s.numRescueBoats(test,limit);
  cout<<result<<endl;
  return 0;
}