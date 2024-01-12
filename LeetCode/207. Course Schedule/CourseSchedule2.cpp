#include <vector>
#include <queue>
#include <unordered_map>
#include <numeric>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
      if(prerequisites.empty()) return true;

      unordered_map<int,vector<int>> outEdges;
      vector<int> inDegree(numCourses,0);
      vector<int> courseComplete(numCourses,0);
      queue<int> q;

      for(int i = 0 ; i < prerequisites.size() ; i++){
        inDegree[prerequisites[i][0]]++;
        outEdges[prerequisites[i][1]].push_back(prerequisites[i][0]);
      }

      for(int i = 0 ; i < inDegree.size() ; i++){
        if(inDegree[i] == 0){
          q.push(i);
        }
      }

      while(!q.empty()){
        int course = q.front();
        q.pop();
        courseComplete[course] = 1;
        for(int next : outEdges[course]){
          if(--inDegree[next]==0) q.push(next);
        }
      }

      if(accumulate(courseComplete.begin(),courseComplete.end(),0)!= numCourses) return false;
      return true; 
    }
};