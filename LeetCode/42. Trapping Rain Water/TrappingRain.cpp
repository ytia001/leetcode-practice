#include <vector>
#include <stack>
#include <deque>
#include <cmath>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
      stack<int> st;
      deque<int> dq;
      int res = 0;
      for(int i = 0 ; i < height.size() ; i++){
        if(dq.empty() && height[i]!=0){
          dq.push_back(height[i]);
          continue;
        }

        if(!dq.empty()){
          int front = dq.front();
          if(front<=height[i]){
            dq.pop_front();
            int current = 0;
            while(!dq.empty()){
              current += abs(dq.front()-front);
              dq.pop_front();
            }
            res += current;
          }

          dq.push_back(height[i]);
        }

      }
    }
};