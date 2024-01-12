#include <iostream>
#include <string>

using namespace std;

class Solution {
public:

    
    bool check(string& current,int i, string n){
      if(i==current.size()) return true;
      for(char k = '9' ; k >= '0' ; k--){
        current[i] = k;
        //cout<<current<<endl;
        // if(stoi(current)>n){
        //   current[i] = '0';
        //   continue;
        // }
        if(current.compare(n)>0){
          current[i] = '0';
          continue;
        }
        else if(i>0 && current[i]<current[i-1]){
          current[i] = '0';
          return false;
        }
        //if(i==current.size()-1) return true;
        if(!check(current,i+1,n)){
          continue;
        }else{
          return true;
        }
      }
      return false;
    }

    // void check(string& current,int i, int n){
    //   for(char k = '9' ; k >= '0' ; k--){
    //     current[i] = k;
    //     cout<<current<<endl;
    //     if(stoi(current)>n){
    //       current[i] = '0';
    //       continue;
    //     }else if(i>0 && current[i]<current[i-1]){
    //       current[i] = '0';
    //       return;
    //     }
    //     check(current,++i,n);
    //   }
    // }

    int monotoneIncreasingDigits(int n) {
      int size = to_string(n).size();
      //int res = 0;
      string start(size,'0');
      //string res = start;
      // cout<<res<<endl;
      check(start,0,to_string(n));
      return stoi(start);
    }
};

int main(){

// for(char k = '9' ; k >= '0' ; k--){
//   // if(stoi(current[i]))
//   cout<<k<<endl;
// }

Solution s;
cout<<s.monotoneIncreasingDigits(1000000000)<<endl;

 return 0;
}