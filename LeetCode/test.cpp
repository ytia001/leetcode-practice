#include<vector>
#include<unordered_map>
#include <unordered_set>
#include <queue>
#include <cmath>
#include <iostream>

using namespace std;


int minScore(int n, vector<vector<int>>& roads) {
    unordered_map<int, unordered_map<int, int>> graph;
    for (auto r : roads) {
        graph[r[0]][r[1]] = graph[r[1]][r[0]] = r[2];
    }

    int res = INT_MAX;
    unordered_set<int> vis;
    queue<int> q;
    q.push(1);
    vis.insert(1);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto [adj, scr] : graph[node]) {
            if (!vis.count(adj)) {
                q.push(adj);
                vis.insert(adj);
            }
            cout<<"res: "<<res<<" scr:"<<scr<<endl;
            res = min(res, scr);
        }
    }
    
    return res;
}

int main(){
  vector<vector<int>> test ={{1,2,9},{2,3,6},{2,4,5},{1,4,7}};
  int a = minScore(4,test);
  return 0;
}