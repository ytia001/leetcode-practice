#include <queue>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    double knightProbability(int n, int k, int row, int column) {
        if(k == 0) return 1;

        double res = 1;
        queue<pair<int,int>> nextPos;
        nextPos.push({row,column});
        vector<pair<int,int>> moves = {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};

        while(k-->0 && !nextPos.empty()){
          int size = nextPos.size();
          double count = 0;
          for(int i = 0 ; i < size ; i++){
            auto[y,x] = nextPos.front();
            nextPos.pop();

            for(auto[dy,dx] : moves){
              int y_n = y + dy;
              int x_n = x + dx;
              if(y_n < 0 || x_n < 0 || y_n >= n || x_n >=n ) continue;
              count++;
              nextPos.push({y_n,x_n});
            }

          }
          cout<<"count: "<<count<<" size: "<<8*size<<endl;
          cout<<"(count)/(8*size): "<<(count)/(8*size)<<endl;
          res *= (count)/(8*size);
        }

        return res; 
    }


    double knightProbability(int n, int k, int row, int column) {
        if(!k) return 0;

        double res = 1;
        queue<pair<int,int>> nextPos;
        //vector<vector<int>> grid(row,vector<int>(column,0));
        //grid[row][column] = 1;
        nextPos.push({row,column});
        vector<pair<int,int>> moves = {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};

        while(k-->0 && !nextPos.empty()){
          int size = nextPos.size();
          int count = 0;
          while(size-- > 0){
            auto[y,x] = nextPos.front();
            nextPos.pop();
            //grid[y][x] = 1;

            for(auto[dy,dx] : moves){
              int y_n = y + dy;
              int x_n = x + dx;
              //if(y_n < 0 || x_n < 0 || y_n >= n || x_n >=n || grid[y_n][x_n] == 1) continue;
              if(y_n < 0 || x_n < 0 || y_n >= n || x_n >=n ) continue;
              count++;
              nextPos.push({y_n,x_n});
            }

          }

          res *= (count)/(8*size);
          // res *= (count)/(8*size);
          //res *= (count)/8;
          //if(!res) return 0;
        }

        return res;
    }
};