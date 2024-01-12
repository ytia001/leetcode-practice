#include "network.hpp"

int Solution::makeConnected(int n, std::vector<std::vector<int>>& connections){

  std::unordered_map<int,std::vector<int>> graph;
  for (auto i : connections){
    graph[i[0]].push_back(i[1]);
    graph[i[1]].push_back(i[0]);
  }
  // for(auto i : graph){
    //   std::cout<<"key" << i.first<<std::endl;
    //   for (auto j : i.second) std::cout<<"links"<<j<<std::endl;
    // }

  if(connections.size()<n-1) return -1;

  std::queue<int> q;
  std::unordered_set<int> visited;
  int uniqueCount = 0;

  // q.push(begin(graph)->first);
  // visited.insert(begin(graph)->first);


  // while(!q.empty()){
  //   int node = q.front();
  //   q.pop();
    
  //   for( auto i : graph[node]){
  //     if(!visited.count(i)){
  //       uniqueCount++;
  //       q.push(i);
  //       visited.insert(i);
  //     }
  //   }
  // }

  for(int i = 0 ; i < n ; i++){
    if(!visited.count(i)){
      q.push(i);
      visited.insert(i);
      while(!q.empty()){
        int node = q.front();
        q.pop();
        for( auto i : graph[node]){
          if(!visited.count(i)){
            uniqueCount++;
            q.push(i);
            visited.insert(i);
            }
         }
        }
      }
    }

 

  // for (int i = 0 ; i < n ; i++){
  //   visited.insert(i);
  //   for ( auto i : graph[i]){
  //     if(!visited.count(i)){
  //       uniqueCount++;
  //       visited.insert(i);
  //     }
  //   }
  // }

  return (n-1)-uniqueCount;
  // return connectedLinksNeeded;
}

int main(){

  std::vector<std::vector<int>> test= {{0,1},{0,2},{0,3},{1,2}};
  Solution s;
  int a = s.makeConnected(6,test);
  std::cout<<a<<std::endl;
  return 0;
}