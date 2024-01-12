#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
      vector<bool> check(s.size(),false);
      for(int i = 1; i < check.size() ; i++){
        for(int j = i-1 ; j>=0 ; j--){
          string s1 = s.substr(0,j+1);
          string s2 = s.substr(j+1,i-j);
          // cout<<s.substr(0,j+1)<<"  "<<s.substr(j+1,i-j)<<endl;
          // cout<<s.substr(j+1).compare(s.substr(j+1,i-j))<<endl;
          if(check[j]){
            check[i] = true;
            break;
          }
          if(s1.compare(s2) == 0){
            check[i] = true;
            break;
          }
        }
      }
      return check[s.size()-1]; 
    }
};