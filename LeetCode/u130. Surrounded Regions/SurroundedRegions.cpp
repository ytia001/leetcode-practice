#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    // bool check(vector<vector<char>>& board, int i , int j){
    //   if(i<0 || i>board.size()-1 || j<0 || j>board[0].size()-1){
    //     return false;
    //   }
    //   if(board[i][j]=='X'){
    //     return true;
    //   }
    //   if(board[i][j]=='O'){
    //     board[i][j] = 'X';
    //   }
      
      
    //   if(check(board,i-1,j) && check(board,i+1,j) && check(board,i,j+1) && check(board,i,j-1)){
    //      board[i][j] = 'Y';
    //      return true;
    //   }else{
    //     board[i][j] = 'N';
    //     return false;
    //   }
    // }


    bool check(vector<vector<char>>& board, int i , int j){
      if(i<0 || i>=board.size() || j<0 || j>=board[0].size()){
        return false;
      }
      if(board[i][j]=='X'){
        return true;
      }
      if(board[i][j]=='O'){
        board[i][j] = 'X';
      }
      
      
      if((check(board, i, j - 1) && check(board, i, j + 1) && check(board, i - 1, j) && check(board, i + 1, j))){
         board[i][j] = 'X';
         return true;
      }else{
        board[i][j] = 'O';
        return false;
      }
    }

    void solve(vector<vector<char>>& board) {
      int m = board.size() , n = board[0].size();
      for (int i = 0 ; i < m ; i ++){
        for(int j = 0 ; j < n ; j++){
          if(board[i][j]=='O'){
            //board[i][j]='X';
            //cout<<"i: "<<i<<"j: "<<j<<check(board,i,j)<<endl;
            check(board,i,j);
          }
        }
      }
    }
};

int main(){
  Solution s;
  vector<vector<char>> test = {
    {'O', 'X', 'X', 'O', 'X'},
    {'X', 'O', 'O', 'X', 'O'},
    {'X', 'O', 'X', 'O', 'X'},
    {'O', 'X', 'O', 'O', 'O'},
    {'X', 'X', 'O', 'X', 'O'}
  };
  s.solve(test);
  for(auto o: test){
    for(auto i : o){
      cout<<i<<" ";
    }
    cout<<endl;
  }
  return 0;
}