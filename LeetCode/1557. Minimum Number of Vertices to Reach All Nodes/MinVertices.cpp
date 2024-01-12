#include<vector>
#include<iostream>
#include<unordered_set>

using namespace std;

class Solution {
public:

    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> check(n,1);
        vector<int> res;

        for(auto pair : edges){
          check[pair[1]] = 0;
          // if(check[pair[1]]==1){
          //   check[pair[1]] = 0;
          // }
        }

        for(int i = 0; i < check.size() ; i++){
          if(check[i]){
            res.push_back(i);
          }
        }

        return res;
    }

    vector<int> findSmallestSetOfVerticesTest2(int n, vector<vector<int>>& edges) {
       
        unordered_set<int> head;
        unordered_set<int> pointed;
        
        head.insert(edges[0][0]);
        pointed.insert(edges[0][1]);
        for(int i = 1 ; i < edges.size() ; i++){
          if(head.count(edges[i][1])){
            head.erase(edges[i][1]);
          }
          
          if(pointed.count(edges[i][0])){
            pointed.insert(edges[i][1]);
          }else{
            head.insert(edges[i][0]);
            pointed.insert(edges[i][1]);
          }

        }

        return vector<int>(head.begin(),head.end());
    }

    vector<int> findSmallestSetOfVerticesTest(int n, vector<vector<int>>& edges) {
       
        unordered_set<int> set;
        for(int i = 0 ; i <n ; i++){
          set.insert(i);
        }

        for(auto pair : edges){
          if(set.count(pair[1])){
            set.erase(pair[1]);
          }
        }

        return vector<int>(set.begin(),set.end());
    }

    
};

int main(){
  Solution s;
  //vector<vector<int>> test = {{0,1},{0,2},{2,5},{3,4},{4,2}};
  vector<vector<int>> test = {{0,1},{2,1},{3,1},{1,4},{2,4}};
  vector<int> result = s.findSmallestSetOfVertices(5,test);
  for(int i : result){
    cout<<i<<endl;
  }
  return 0;
}