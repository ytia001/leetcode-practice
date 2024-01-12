#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    double dfsResult;

public:
    double dfs(unordered_map<string,unordered_map<string,double>>& eq,unordered_set<string> visited, string nominator , string denominator, double result){
      if(nominator==denominator) {
        dfsResult = result;
      };
      unordered_map<string,double> adjNode = eq[nominator];
      for(auto i : adjNode ){
        if(!visited.count(i.first)){
          visited.insert(i.first);
          dfs(eq,visited,i.first,denominator,result*i.second);
        }
      }
      
      return dfsResult;
    }


    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int size = equations.size();
        int qSize = queries.size();
        unordered_map<string,unordered_map<string,double>> eq;
        unordered_set<string> variables;
        vector<double> res(qSize,-1);

        for(int i = 0 ; i < size ; i++){
          string nominator = equations[i][0], denominator = equations[i][1];
          double val = values[i];
          variables.insert(nominator); variables.insert(denominator);
          eq[nominator][denominator] = val;
          eq[denominator][nominator] = 1/val;
        }

        for(int i = 0 ; i < qSize ; i++){
          string nominator = queries[i][0];
          string denominator = queries[i][1];
          if(variables.count(nominator) && variables.count(denominator)){
            if(eq[nominator].find(denominator)==eq[nominator].end()){
              unordered_set<string> visited;
              visited.insert(nominator);
              dfsResult = -1;
              res[i] =  dfs(eq,visited,nominator,denominator,1);
            }
            else{
              res[i] = eq[nominator][denominator];
            }
          }
        }
        return res;
    }
};

int main(){
  Solution s;
  vector<vector<string>> equations = {{"a","b"},{"b","c"},{"a","c"},{"d","e"}};
  vector<double> values = {2.0,3.0,6.0,1.0};
  vector<vector<string>> queries = {{"a","c"},{"b","c"},{"a","e"},{"a","a"},{"x","x"},{"a","d"}};
  vector<double> result = s.calcEquation(equations,values,queries);
  for(auto i : result){
    cout<<"result: "<<i<<endl;
  }
  return 0;
}