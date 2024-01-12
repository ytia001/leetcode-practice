#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int maxRowIdx = (matrix.size()-1)/2;
        int maxColIdx = (matrix[0].size()-1)/2;
        int curTotalRow = matrix.size(), curTotalcol = matrix[0].size();
        int rowStart = 0 , colStart = 0;

        while(rowStart<= maxRowIdx && colStart <= maxColIdx){
            outerOrder(matrix,result,rowStart++,colStart++, curTotalRow-- , curTotalcol--);
            // m -= 1;
            // n -= 1;
        }
        return result;
    }

    void outerOrder(vector<vector<int>>& matrix,vector<int>& ordered, int rowStart , int colStart, int curTotalRow , int curTotalcol){

        int rs = rowStart , re = curTotalRow-1 , cs = colStart , ce = curTotalcol-1;
        int i = rowStart , j = colStart;

        if((re-rs) ==0){
            while(j<=ce){
                cout<<"0j: "<<matrix[i][j]<<endl;
                ordered.push_back(matrix[i][j]);
                j++;
            }
            return;
        }else if ((ce-cs)==0){
            while(i<=re){
                cout<<"0i: "<<matrix[i][j]<<endl;
                ordered.push_back(matrix[i][j]);
                i++;                
            }
            return;
        } 


        while(j<ce){
            cout<<"1: "<<matrix[i][j]<<endl;
            ordered.push_back(matrix[i][j]);
            j++;
        }
        while(i<re){
            cout<<"2: "<<matrix[i][j]<<endl;
            ordered.push_back(matrix[i][j]);
            i++;
        }
        while(j>cs){
            cout<<"3: "<<matrix[i][j]<<endl;
            ordered.push_back(matrix[i][j]);
            j--;
        }
        while(i>rs){
            cout<<"4: "<<matrix[i][j]<<endl;
            ordered.push_back(matrix[i][j]);
            i--;
        }
        return;
    }

   
}; 


vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<vector<int> > dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<int> res;
    int nr = matrix.size();     if (nr == 0) return res;
    int nc = matrix[0].size();  if (nc == 0) return res;
    
    vector<int> nSteps{nc, nr-1};
    
    int iDir = 0;   // index of direction.
    int ir = 0, ic = -1;    // initial position
    while (nSteps[iDir%2]) {
        for (int i = 0; i < nSteps[iDir%2]; ++i) {
            ir += dirs[iDir][0]; ic += dirs[iDir][1];
            res.push_back(matrix[ir][ic]);
        }
        nSteps[iDir%2]--;
        iDir = (iDir + 1) % 4;
    }
    return res;
}

int main(){
        Solution s;
        //vector<vector<int>> test = {{1,2,3},{4,5,6},{7,8,9}};
        //vector<vector<int>> test ={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
        vector<vector<int>> test ={{1,2,3,4,5,6,7,8,9,10},{11,12,13,14,15,16,17,18,19,20}};
        //vector<vector<int>> test ={{1,2,3,4,5,6,7}};
        //vector<vector<int>> test ={{1},{2},{3},{4},{5},{6}};
        vector<int> result;
        s.spiralOrder(test);
        // for(auto i : result){
        //     cout<<i<<endl;
        // }
        return 0;
    }