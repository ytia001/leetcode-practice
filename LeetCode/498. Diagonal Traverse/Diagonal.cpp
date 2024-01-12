# include <vector>
# include <queue>
# include <stack>

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
      int m = mat.size() , n = mat[0].size();
      int target = min(m,n), extra = abs(m-n);
      vector<int> res(m*n,0);
      vector<int> spread;
      queue<int> qOdd;
      stack<int> qEven;

      for(int i = 0 , k = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
          if(k%2 != 0){
            qOdd.push(mat[i][j]);
          }else{
            qEven.push(mat[i][j]);
          }
          k++;
        }
      }

      int amount = 1;
      while(1){
        while(amount < target){
          spread.push_back(amount++);
        }
        while(extra-- >= 0){
          spread.push_back(target);
        }
        while(amount > 1){
         spread.push_back(--amount); 
        }
        break;
      }

      for(int i = 0 ; i < spread.size() ; i++){
        int ptr = 0;
        if( i%2 != 0){
          int count = spread[i];
          while(count -- > 0){
            res[ptr++] = qOdd.front();
            qOdd.pop();
          }
        }else{
          ptr += spread[i];
        }
      }

      return res; 
    }
};




 // for(int i = 1 ; i < target ; i++){
      //   for(int j = 0 ; j < i ; j++){
      //     if(isOdd){
      //       res.push_back(qOdd.front());
      //       qOdd.pop();
      //     }else{
      //       res.push_back(qEven.top());
      //       qEven.pop();
      //     }
      //   }
      //   isOdd = !isOdd;
      // }

      // for(int i = 0 ; i <= extra ; i++){
      //   for(int j = 0 ; j < target ; j++){
      //     cout<<"number :"<<j<<endl;
      //     if(isOdd){
      //       res.push_back(qOdd.front());
      //       qOdd.pop();
      //     }else{
      //       res.push_back(qEven.front());
      //       qEven.pop();
      //     }
      //   }
      //   isOdd = !isOdd;
      // }

      // for(int i = target - 1 ; i > 0 ; i--){
      //   for(int j = 0 ; j < i ; j++){
      //     if(!isOdd){
      //       res.push_back(qEven.front());
      //       qEven.pop();
      //     }else{
      //       res.push_back(qOdd.front());
      //       qOdd.pop();
      //     }
      //     isOdd = !isOdd;
      //   }
      // }