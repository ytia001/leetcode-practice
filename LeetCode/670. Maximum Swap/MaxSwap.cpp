#include <algorithm>
#include <string>
#include <queue>
using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
      if(!num) return 0;
      string num_string = to_string(num);
      int size = num_string.size();
      int dp[size];
      for(int i = size-1 ; i >= 0 ; i--){
        if(i == size-1) {
          dp[i] = size - 1;
          continue;
        }
        //dp[i] = num_string[dp[i+1]] > num_string[i] ? dp[i+1]: num_string[dp[i+1]] == num_string[i] ? dp[i+1] : i;
        dp[i] = num_string[dp[i+1]] >= num_string[i] ? dp[i+1] : i;
      }


      for(int i = 0 ; i < num_string.size() ; i++){
        if(num_string[i] < num_string[dp[i]]){
          swap(num_string[i],num_string[dp[i]]);
          break;
        }
      }
      
      return stoi(num_string);
    } 
    }

    // int maximumSwap(int num) {
    //   if(!num) return 0;
    //   string num_string = to_string(num);
    //   // int idx = 0, val = num_string[0]-'0';
    //   queue<int> q;
    //   q.push(0);
    //   for(int i = 1 ; i < num_string.size() ; i++){
    //     // while(!q.empty() && num_string[q.front()] >= num_string[i]){
    //     //   q.pop();
    //     // }

    //     while(!q.empty() && num_string[q.front()] >= num_string[i]){
    //       continue;
    //     }

    //     if(!q.empty()){
    //       swap(num_string[q.front()],num_string[i]);
    //       break;
    //     }else{
    //       q.push(i);
    //     }
    //   }

    //   return stoi(num_string);
    // }
};