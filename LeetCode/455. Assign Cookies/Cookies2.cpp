# include <vector>
# include <algorithm>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
      sort(s.begin(),s.end());
      sort(g.begin(),g.end());
      int j = 0 , res = 0;
      for(int i = 0 ; i < g.size() && j < s.size(); i++){
        while(j<s.size() && g[i] > s[j]){
          j++;
        }
        if(j < s.size() && g[i] <= s[j]) {
          j++;
          res++;
        }
      } 
      return res; 
    }
};

