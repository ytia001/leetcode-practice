#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
      //int size = (a.size()>=b.size())? a.size() : b.size();
      //  vector<int> container(size,0);
      string res;
      int multi = 0;
      int ptrA = a.size()-1 , ptrB = b.size()-1;
      while(ptrA>0 || ptrB > 0){
        string curA = "0", curB = "0";
        if(ptrA>0){
          if(a[ptrA]=='1'){
            curA = "1" + ('0'*multi);
          }
        }
        if(ptrB>0){
          if(b[ptrB]=='1'){
            curB = "1" + ('0'*multi);
          }
        }
        multi++;
      }
    }
};