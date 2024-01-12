#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
      int res = num;
      if(!num) return res;
      while(res>9){
        string test = to_string(res); 
        res = 0;
        for(auto i : test){
          res += (i-'0');
          //cout<<(int)i<<endl;
          //cout<<i<<endl;
        }

      }
      return res;
    }
};

int main(){
  Solution s;
  cout<<s.addDigits(38)<<endl;
  return 0;
}