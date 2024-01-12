#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
class SnapshotArray {
private:
    int id;
    vector<int> prev;
    vector<int> current;
    unordered_map<int,vector<pair<int,int>>> map;
public:
    SnapshotArray(int length) {
      id = 0;
      vector<int> copy(length,0);
      prev = copy , current = copy;
      // for(int i = 0 ; i < length ; i++){
      //   map[i].push({id,0});
      // }
    }
    
    void set(int index, int val) {
      if(!map[index].empty()){
        auto top = map[index].back(); 
        if(top.first==id){
          map[index].pop_back();
          // map[index].push({id,val});
         }
          map[index].push_back({id,val});
      }else{
          map[index].push_back({id,val});
      }
      // auto top = map[index].top(); 
      // if(top.first==id){
      //   map[index].pop();
      //   // map[index].push({id,val});
      // }
      // map[index].push({id,val});
    }
    
    int snap() {
      ++id;
      return id-1;  
    }
    
    int get(int index, int snap_id) {
      auto indexStack = map[index];
      int res = 0;
      
      while(!indexStack.empty()){
        auto top = indexStack.top();
        indexStack.pop();
        if(top.first<=snap_id){
          return top.second;
        }
      }
      return res;
    }
};

// class SnapshotArray {
// private:
//     int id;
//     vector<int> prev;
//     vector<int> current;
//     unordered_map<int,stack<pair<int,int>>> map;
// public:
//     SnapshotArray(int length) {
//       id = 0;
//       vector<int> copy(length,0);
//       prev = copy , current = copy;
//       // for(int i = 0 ; i < length ; i++){
//       //   map[i].push({id,0});
//       // }
//     }
    
//     void set(int index, int val) {
//       if(!map[index].empty()){
//         auto top = map[index].top(); 
//         if(top.first==id){
//           map[index].pop();
//           // map[index].push({id,val});
//          }
//           map[index].push({id,val});
//       }else{
//           map[index].push({id,val});
//       }
//       // auto top = map[index].top(); 
//       // if(top.first==id){
//       //   map[index].pop();
//       //   // map[index].push({id,val});
//       // }
//       // map[index].push({id,val});
//     }
    
//     int snap() {
//       ++id;
//       return id-1;  
//     }
    
//     int get(int index, int snap_id) {
//       auto indexStack = map[index];
//       int res = 0;
//       while(!indexStack.empty()){
//         auto top = indexStack.top();
//         indexStack.pop();
//         if(top.first<=snap_id){
//           return top.second;
//         }
//       }
//       return res;
//     }
// };

int main(){


 SnapshotArray* obj = new SnapshotArray(5);
 obj->set(1,4);
 int id = obj->snap();
 int param_3 = obj->get(1,id);
 cout<<param_3<<endl;

}

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */