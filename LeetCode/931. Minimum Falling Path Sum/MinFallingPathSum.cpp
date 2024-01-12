#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int answer(vector<vector<int>>& A) {
        for (auto i = 1; i < A.size(); ++i)
            for (auto j = 0; j < A.size(); ++j)
            A[i][j] += min({ A[i-1][j], A[i-1][max(0,j-1)], A[i-1][min((int)A.size()-1,j+1)] });
        return *min_element(begin(A[A.size() - 1]), end(A[A.size() - 1]));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        //int container[matrix.size()][matrix[0].size()];
        vector<vector<int>> container(matrix.size(),vector<int>(matrix.size()));
        int res = INT_MAX;
        for(int i = 0 ; i < matrix.size() ; i++){
            for(int j = 0 ; j < matrix[0].size() ; j++){
                if(i==0){
                    container[i][j] = matrix[i][j];
                    // cout<<container[i][j]<<endl;
                    continue;
                }
                if(j==0){
                    container[i][j] = matrix[i][j] + min(container[i-1][j],container[i-1][j+1]);
                    //cout<<container[i][j]<<endl;
                }else if (j==matrix[0].size()-1){
                    container[i][j] =  matrix[i][j] + min(container[i-1][j],container[i-1][j-1]);
                    //cout<<container[i][j]<<endl;
                }else{
                    container[i][j] =  matrix[i][j] + min(container[i-1][j],min(container[i-1][j+1],container[i-1][j-1]));
                    //cout<<container[i][j]<<endl;
                }
            }
        }

        for(int j = 0 ; j < matrix[0].size() ; j++){
            res = min(res,container[matrix.size()-1][j]);
        }
        

        // return *min_element(container[container.size()-1].begin(),container[container.size()-1].end());
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> test= {{2,1,3},{6,5,4},{7,8,9}};
    cout<<s.minFallingPathSum(test)<<endl;
    return 0;
}