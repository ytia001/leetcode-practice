#include <queue>
#include <vector>
#include <string>
#include <set>

using namespace std;

class Solution {
public:

  
   bool dfs (vector<vector<char>>& board, string word, int index ,int i ,int j, set<pair<int,int>>& history){
      if(i < 0 || j < 0 || i > board.size() -1 || j > board[0].size() - 1 || history.count({i,j}) || board[i][j] != word[index]) return false;
      if(index==word.size()-1) return true;
      history.insert({i,j});

      if(dfs(board,word,index+1,i,j+1,history)) return true;
      if(dfs(board,word,index+1,i-1,j,history)) return true;
      if(dfs(board,word,index+1,i,j-1,history)) return true;
      if(dfs(board,word,index+1,i+1,j,history)) return true;

      return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
      set<pair<int,int>> history;
      for(int i = 0 ; i < board.size() ; i++){
        for(int j = 0 ; j < board[0].size() ; j++){
          if(board[i][j]==word[0]){
            bool result = dfs(board,word,0,i,j,history);
            if(result) return true;
            history.clear();
          }
        }
      }
      return false;
    }

  //  bool bfs(vector<vector<char>>& board,string word, int i ,int j){
  //     int start = 0;
  //     int m = board.size() , n = board[0].size();
  //     queue<pair<int,int>> q;
  //     set<pair<int,int>> st;
  //     q.push({i,j});
  
  //     vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
  //     while(!q.empty() ){
  //       int size = q.size();
  //       start++;
  //       //cout<<"start: "<<start<<endl;
  //       if(start==word.size()) return true;
  //       char nextCh = word[start];
  //       while(size-->0){
  //         auto[i,j] = q.front();
  //         //cout<<i<<"  "<<j<<endl;
  //         q.pop();
  //         //st.insert({i,j});
  //         int counter = 0;
  //         for(auto& k : dir){
  //           int i_n = i + k[0];
  //           int j_n = j + k[1];
  //           if(i_n < 0 || j_n < 0 || i_n >= m || j_n >= n || st.count({i_n,j_n}) || board[i_n][j_n] != nextCh) continue;
  //           //cout<<":"<<i_n<<"  "<<j_n<<endl;
  //           q.push({i_n,j_n});
  //           st.insert({i_n,j_n});
  //           counter++;
  //         }
  //         if(counter == 0) st.erase({i,j});
  //       }
  //     }

  //     return false;
  //   }
    
    
  //   bool exist(vector<vector<char>>& board, string word) {
  //     int start = 0;
  //     int m = board.size() , n = board[0].size();

  //     for(int i = 0 ; i < m ; i++){
  //       for(int j = 0 ; j < n ; j++){
  //         if(board[i][j] == word[start]){
  //           if(bfs(board,word,i,j)) return true;
  //         }
  //       }
  //     }
  //     return false;
  //   }


  //  bool dfs (vector<vector<char>>& board, string word, int index ,int i ,int j, set<pair<int,int>>& history){
  //     if(i < 0 || j < 0 || i > board.size() -1 || j > board[0].size() - 1 || history.count({i,j}) || board[i][j] != word[index]) return false;
  //     if(index==word.size()-1) return true;
  //     history.insert({i,j});

  //     if(dfs(board,word,index+1,i,j+1,history)) return true;
  //     if(dfs(board,word,index+1,i-1,j,history)) return true;
  //     if(dfs(board,word,index+1,i,j-1,history)) return true;
  //     if(dfs(board,word,index+1,i+1,j,history)) return true;

  //     return false;
  //   }

  //   bool exist(vector<vector<char>>& board, string word) {
  //     set<pair<int,int>> history;
  //     for(int i = 0 ; i < board.size() ; i++){
  //       for(int j = 0 ; j < board[0].size() ; j++){
  //         if(board[i][j]==word[0]){
  //           bool result = dfs(board,word,0,i,j,history);
  //           if(result) return true;
  //           history.clear();
  //         }
  //       }
  //     }
  //     return false;
  //   }


    //  bool exist(vector<vector<char>>& board, string word) {
    //   int start = 0;
    //   int m = board.size() , n = board[0].size();
    //   queue<pair<int,int>> q;
    //   for(int i = 0 ; i < m ; i++){
    //     for(int j = 0 ; j < n ; j++){
    //       if(board[i][j] == word[start]){
    //         q.push({i,j});
    //       }
    //     }
    //   }

    //   if(q.empty()) return false;
    //   vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
    //   while(!q.empty() ){
    //     int size = q.size();
    //     start++;
    //     if(start==word.size()) return true;
    //     char nextCh = word[start];
    //     while(size-->0){
    //       auto[i,j] = q.front();
    //       q.pop();
    //       board[i][j] = '0';
    //       for(auto& k : dir){
    //         int i_n = i + k[0];
    //         int j_n = j + k[1];
    //         if(i_n < 0 || j_n < 0 || i_n >= m || j_n >= n || board[i_n][j_n] != nextCh) continue;
    //         q.push({i_n,j_n});
    //       }
    //     }
    //   }

    //   return false;
    // }
};