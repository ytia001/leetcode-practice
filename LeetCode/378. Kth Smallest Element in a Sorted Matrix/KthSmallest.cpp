#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // return matrix[k<=matrix.size() ? 0:k/matrix.size()][(k-1)%matrix.size()];
        // int size = matrix.size()*matrix.size();
        priority_queue<int,vector<int>,less<int>> pq;
        for(int i = 0 ; i < matrix.size() ; i++){
          for(int j = 0 ; j < matrix[0].size() ; j++){
            if(pq.size()<k){
                pq.push(matrix[i][j]);
            }else{
              if(pq.top()>matrix[i][j]){
                pq.pop();
                pq.push(matrix[i][j]);
              }
            }
          }
        }

        return pq.top();
    }
};