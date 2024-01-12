#include <vector>

using namespace std;

class Solution {
public:


    vector<int> countBits(int n) {
      vector<int> res(n+1,0);
      res[0] = 0;
      if(n>0) res[1] = 1;
      for(int i = n ; i > 1 ; i--){
        int count = i;
        int remainder;
        while(count>1){
          // if(res[count])
          remainder = count%2;
          if(remainder) res[i]++;
          count /= 2;
        }
        if(count) res[i]++;
      }  
      return res;
    }

    vector<int> countBits(int n) {
      vector<int> res(n+1,0);
      res[0] = 0;
      if(n>0) res[1] = 1;
      for(int i = 2 ; i <= n ; i++){
        int count = i;
        int remainder;
        while(count>1){
          // if(res[count])
          remainder = count%2;
          if(remainder) res[i]++;
          count /= 2;
        }
        if(count) res[i]++;
      }  
      return res;
    }

    // vector<int> countBits(int n) {
    //   int maxWidth = 1;
    //   int maxSpace = 0;
    //   int multi = 1;
    //   vector<int> res(n+1,0);
    //   res[0] = 0;
    //   if(n>0) {
    //     res[1] = 1;
    //     //maxSpace--;
    //   }

    //   for(int i = 2 ; i <res.size() ; i++){
    //     if(maxSpace == 0){
    //       cout<<"multi: "<<multi<<" maxWidth: "<<maxWidth<<" maxSpace: "<<maxSpace <<endl;
    //       multi *= maxWidth;
    //       maxWidth++;
    //       maxSpace = multi;
    //       cout<<"multi: "<<multi<<" maxWidth: "<<maxWidth<<" maxSpace: "<<maxSpace <<endl;
    //       res[i] = 1;
    //     }else{
    //       maxSpace--;
    //       res[i] = res[i-1] + 1;
    //     }
    //     cout<<"res[i]: "<<res[i]<<endl;
    //   }

    //   return res;
    // }

    // vector<int> countBits(int n) {
    //   int maxSpace = 1;
    //   vector<int> res(n+1,0);
    //   res[0] = 0;
    //   if(n>0) res[1] = 1;
    //   for(int i = 2 ; i <res.size() ; i++){
    //     // if(i%2 == 0) maxBits++;
    //     // if( res[i-1] + 1 < maxBits ){
    //     //   res[i] = res[i-1] + 1; 
    //     // }else{
    //     //   res[i] = 1;
    //     // }

    //   }

    //   return res;
    // }
};