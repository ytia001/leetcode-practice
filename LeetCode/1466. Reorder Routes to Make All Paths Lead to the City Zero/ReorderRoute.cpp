#include "ReorderRoute.hpp"

 int Solution::minReorder(int n, std::vector<std::vector<int>>& connections){
    std::unordered_map<int,std::unordered_set<int>> roads;
    std::unordered_map<int,std::vector<int>> graph;
    for (auto i : connections){
      roads[i[0]].insert(i[1]);
      graph[i[0]].push_back(i[1]);
      graph[i[1]].push_back(i[0]);
    }
  
    int roadChange = 0 ;
    std::unordered_set<int> visited;
    visited.insert(0);
    std::function<void(int,int)> a;

    a = [&](int inputNode, int prevNode )->void
    {

      for(auto neigh : graph[inputNode]){
        if(!visited.count(neigh)){
          //std::cout<<"currentNode: "<<neigh<<"previous Node: "<<prevNode<<std::endl;  
          visited.insert(neigh);
          // if(roads.find(prevNode)==roads.end() || (roads[inputNode] != prevNode) ){
            // if(roads.find(i)==roads.end() || (roads[i] != inputNode) ){
            //std::cout<<"roads[neigh]: "<<roads[neigh]<<"previous Node: "<<prevNode<<std::endl;  
            if(roads.find(neigh)==roads.end() || (!roads[neigh].count(prevNode) )){
              // std::cout<<"currentNode: "<<neigh<<"previous Node: "<<prevNode<<std::endl;
              roadChange++;
          }
          a(neigh,neigh);
        }
         
      }
      return;
    };

    a(0,0);

    return roadChange;

 }

 int main(){
  Solution s;
  std::vector<std::vector<int>> test= {{1,0},{2,0}};
  int n = 3;
  std::cout<< s.minReorder(n,test);
  return 0 ;
 }