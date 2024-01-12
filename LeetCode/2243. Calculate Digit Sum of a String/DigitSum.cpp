#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string digitSum(string s, int k) {
        if(s.length()<=k){
          return s;
        }
        int i = 0;
        string newString = "";
        int currentTotal = 0;
        while(i<s.length()){
          currentTotal += s[i]-48;
          // cout<<"currentTotal: "<<currentTotal<<endl;
          if( ((i+1)%k==0) || i == s.length()-1){
            newString += to_string(currentTotal);
            // cout<<"currentTotal: "<<currentTotal<<endl;
            currentTotal = 0;
          }
          i++;
        }
        cout<<"newString: "<<newString<<endl;
        return digitSum(newString,k);
    }
};

int main(){
  Solution s;
  string test = "11111222223";
  cout<<s.digitSum(test,3)<<endl;
  return 0 ;
}