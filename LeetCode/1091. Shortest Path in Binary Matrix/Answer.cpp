#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n =  grid.size();
        
        // If the starting point or ending point is 1, then you will not be able to start or end, so return -1
        if( grid[0][0] || grid[n-1][n-1] )
            return -1;
        
        
        // Consider a min priority queue( PQ )
        // In PQ, the top element is the node that can takes us to the target location with the least number of steps
        priority_queue< vector<int>, vector<vector<int>>, greater<vector<int>> > PQ;
        
        
        // moving form [0,0] to [n-1,n-1] is equal to [n-1,n-1] to [0,0]
        // therefor push [n-1,n-1]th loc as staring and [0,0] as ending
        PQ.push( { n, n-1, n-1, 1} );
        // { heuristic value : n,
        //   row index : n-1,
        //   column index : n-1,
        //   steps covered : 1  }
        
        
        
        while( !PQ.empty() ){
            
            // Pick the node that says "I can get you to your destination in fewer steps". that node might
            // not be right, but if the node can able convey the right message, then we can save a lot of
            // time that might otherwise be wasted exploring all the nodes (similar to BFS);
            vector<int> v = PQ.top();
            PQ.pop();
            
            int i = v[1], j = v[2];
            
            // Verify that [i,j] loc belongs to the grid. If it does, then its value must be zero.
            if( i < 0 || i >= n || j < 0 || j >= n || grid[i][j] )
                continue;
            
            // If [i,j] is [0,0] then we are at our destination. We must stop here and return no. of steps covered.
            if( i == 0 && j == 0 )
                return v[3];
            
        
            grid[i][j] = 2;// Marking the node as visited so that we won't visit again
            // cout<< i << "  " << j <<endl ;
            
            
            // Insert all adjcent node in PQ;
            // add heuristic value for all adjcent nodes
            for (auto p = -1; p < 2; ++p){
                for (auto q = -1; q < 2; ++q){
                    int x = p+i, y = q+j ;
                    if ( p || q ) PQ.push( { max(x,y)+v[3], x, y, v[3]+1 } );
                }
            }
            
            
        }// If PQ becomes empty then we won't be able to reach our destination.
        // So return -1;
        
        return -1;
    }
};