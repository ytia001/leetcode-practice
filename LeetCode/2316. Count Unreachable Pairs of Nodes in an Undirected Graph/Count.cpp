#include "Count.hpp"

void dfs(int startNode, std::unordered_set<int>& visited,std::unordered_map<int,std::unordered_set<int>>& graph,int& connectedNodes){
   visited.insert(startNode);
   connectedNodes++;
  for(int i : graph[startNode]){
    if(!visited.count(i)){
      // std::cout<<"i: "<<i<<std::endl;
      dfs(i,visited,graph,connectedNodes);
    }
  }
}

long long Solution::countPairs(int n, std::vector<std::vector<int>>& edges){
  long long total = 0;
  std::unordered_map<int,std::unordered_set<int>> graph;
  //int otherGroup= n;
  std::queue<int> groups;

  for (int i = 0 ; i < edges.size() ; i++){
    graph[edges[i][0]].insert(edges[i][1]);
    graph[edges[i][1]].insert(edges[i][0]);
  }

    std::unordered_set<int> visited;
  for(int i = 0 ; i < n ; i ++){
    if(!visited.count(i)){
      int connectedNodes = 0;
      dfs(i,visited,graph,connectedNodes);
      groups.push(connectedNodes);
      std::cout<<connectedNodes<<std::endl;
    }  

  
}
  while(!groups.empty()){
    long long  currentGroup = groups.front();
    groups.pop();
    n -= currentGroup;
    total += currentGroup * n ;
    }
return total ;
}

int main(){

  std::vector<std::vector<int>> test = {{0,2}, {0,5} , {2,4},{1,6},{5,4}};
  Solution s;
  std::cout<<s.countPairs(7,test)<<std::endl;
  return 0;
}

// void dfs(int startNode, std::unordered_set<int>& visited,std::unordered_map<int,std::unordered_set<int>>& graph,int& connectedNodes){
//    //visited.insert(startNode);
//   for(int i : graph[startNode]){
//     if(!visited.count(i)){
//       visited.insert(i);
//       std::cout<<"i: "<<i<<std::endl;
//       connectedNodes ++;
//       dfs(i,visited,graph,connectedNodes);
//     }
//   }
  
// }

// long long Solution::countPairs(int n, std::vector<std::vector<int>>& edges){
//   int connectedNodes = 0;
//   long long total = 0;
//   std::unordered_map<int,std::unordered_set<int>> graph;
//   int size = n;
//   // std::vector<int> nodesLeft(n,1);
//   // std::unordered_set<int> visited; 

//   // std::cout<<edges.size()<<std::endl;
//   for (int i = 0 ; i < edges.size() ; i++){
//     // std::cout<<edges[i][0]<<edges[i][1]<<std::endl;
//     graph[edges[i][0]].insert(edges[i][1]);
//     graph[edges[i][1]].insert(edges[i][0]);
//   }

//   // for (int i = 0 ; i < graph.size() ; i++ ){

//   //   std::cout<<i<<std::endl;
//   //   for (int j : graph[i]) std::cout<<j<< "  ";
//   //   std::cout<<" "<<std::endl;
//   // }
//   // for(auto i :nodesLeft) std::cout<<i<<std::endl;
//     std::unordered_set<int> visited;
//   for(int i = 0 ; i < n ; i ++){
//     visited.insert(i);
//     std::unordered_set copy(visited.begin(),visited.end());
//     int overallConnectedNodes = 0;
//     dfs(i, copy , graph, overallConnectedNodes);
//     std::cout<<overallConnectedNodes <<std::endl;
  
//     total += (--size) - overallConnectedNodes;  
//       // std::cout<<"connectedNodes"<<overallConnectedNodes<<std::endl;
//       // std::cout<<"size"<<size<<std::endl;
  
// }

// return total ;
// }

