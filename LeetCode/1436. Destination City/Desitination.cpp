#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
      unordered_set<string> st;
      for(auto& path : paths){
        if(st.count(path[0])){ 
          st.erase(path[0]);
        }else{
          st.insert(path[0]);
        }
        
        if(st.count(path[1])){
          st.erase(path[1]);
        }else{
          st.insert(path[1]);
        }
      }

      for(auto& path :paths){
        if(st.count(path[1])){
          return path[1];
        }
      }

      return "";
    }
};