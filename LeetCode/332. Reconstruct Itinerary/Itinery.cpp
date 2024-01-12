#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:

    vector<string> res;
    unordered_map<string,vector<string>> grid;

    void dfs(unordered_map<string,unordered_map<string,int>>& countPlaces,string start, string end, int travels, vector<string>& temp){
      cout<<travels<<"---"<<end<<endl;
      temp.push_back(end);
      countPlaces[start][end]--;

      if(travels==0){
        int i = 0;
        if(res.empty()) {
            res = temp;
            return;
        }
        while(i<res.size()){
        //   cout<<res[i]<<"---"<<temp[i]<<endl;
        //   cout<<res[i][0] <<"---"<<temp[i][0]<<endl;
          if(res[i][0] < temp[i][0]){
            res.clear();
            res = temp;
            return;
          }
          else if(res[i][0] > temp[i][0]){
            return;
          }else{
            i++;
          }
        }
        return;
      }

      for(auto& toPlace : grid[end]){
        if(countPlaces[end][toPlace] <= 0) continue;
        dfs(countPlaces,end,toPlace,travels-1,temp);
        countPlaces[end][toPlace]++;
        temp.pop_back();
      }

      return;

    }


    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,unordered_map<string,int>> countPlaces;
        vector<string> temp;
        temp.push_back({"JFK"});
        int travels = tickets.size();

        for(int i = 0 ; i < tickets.size() ; i++){
          grid[tickets[i][0]].push_back(tickets[i][1]);
          countPlaces[tickets[i][0]][tickets[i][1]]++;
        }

        for(auto& toPlace : grid["JFK"]){
          if(countPlaces["JFK"][toPlace] < 0) continue;
          dfs(countPlaces,"JFK",toPlace,travels-1,temp);
          cout<<"e"<<endl;
        }
        for(auto i : res) cout<<"res: "<<i<<endl;
        return res;
    }
};