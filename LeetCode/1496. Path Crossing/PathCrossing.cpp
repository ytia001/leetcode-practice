# include <string>
# include <set>

using namespace std;

class Solution {
public:
    bool isPathCrossing(string path) {
      set<pair<int,int>> st;
      pair<int,int> coord = {0,0};
      st.insert(coord);

      for(int i = 0 ; i < path.size() ; i++){
        if(path[i] == 'N'){
          coord.second += 1;
        }
        else if (path[i] == 'S'){
          coord.second -=1;
        }
        else if (path[i] == 'E'){
          coord.first += 1;
        }
        else {
          coord.first -=1;
        }

        if(st.count(coord)){
          return true;
        }else{
          st.insert(coord);
        }
      }

      return false;
    }
};