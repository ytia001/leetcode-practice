#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        //int next = 0;
        while(n>=7){
          int next = 0;
          while(n!=0){
            next += pow(n%10,2);
            n /= 10;
          }
          n = next;
          // cout<<"n: "<<n<<endl; 
        }
        if(n!= 1) return false;
        return true;
    }
};

int main(){
  Solution s;
  s.isHappy(5) ? cout<<"true"<<endl : cout<<"false"<<endl;
  return 0;
}