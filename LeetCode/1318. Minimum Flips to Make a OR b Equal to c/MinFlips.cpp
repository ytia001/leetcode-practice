#include <iostream>

using namespace std;

class Solution {
public:
    int minFlips(int a, int b, int c) {
      int res = 0;
      for(int i = 1; i<=a || i<=b || i<=c ; i = i << 1){
        cout<<i<<endl;
        if(c&i){
          if(a&i||b&i){
            // cout<<"1"<<i<<endl;
          }else{
            //  cout<<"2"<<i<<endl;
            res++;
          }
        }else{
          if(a&i && b&i){
            //  cout<<"3"<<i<<endl;
            res += 2;
          }else if(a&i||b&i){
            //  cout<<"4"<<i<<endl;
            res++;
          }
        }
      }
      return res;
    }
};

int main(){
  Solution s;
  cout<<s.minFlips(8,3,5)<<endl;
  return 0;
}