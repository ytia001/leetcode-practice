#include <iostream>
#include <cmath>
#include <unordered_map>
using namespace std;

class Solution {
public:

    int numberDiv(int target){
      int fix = target;
      int count = 0;
      while(target!=1){
        if(fix%target == 0){
          count++;
        }
        target--;
      }
      return count;
    }

    int bulbSwitch(int n){
      int on = n ;
      unordered_map<int,int> numToNumDiv;
      if(on){
        on = 1;
      }else{
        return 0;
      }
      for (int i = 2 ; i <= n ; i++){
        int indicator = pow(-1,numberDiv(i)) ;
        //int indicator = 0;
        // (i%2 != 0) ? indicator = -1 : indicator = pow(-1,numberDiv(i));
        //cout<<indicator<<endl;
        if(indicator == 1){
          on++;
        }
      }
      return on;
    }

    int answer(int n) {
    return sqrt(n);
    }

    // int bulbSwitch(int n) {
    //     int on = n;
    //     int even = 0 ;
    //     int odd = 0;
    //     int oddCount = 0;
    //     int evenCount = 0;
    //     for (int i = 2 ; i <n ; i++){
    //       (i%2 == 0) ? evenCount++ : oddCount++; 
    //       int change = n/i;
    //       if(evenCount%2 != 0 || oddCount%2 !=0){
    //          (i%2 == 0) ? even += -change : odd += -change;
    //          cout<<"even: "<<even<<"odd: "<<odd<<endl;
    //       }else{
    //          (i%2 == 0) ? even += change : odd += change;
    //          cout<<"even: "<<even<<"odd: "<<odd<<endl;
    //       }
    //     }
    //     cout<<"on: "<<on<<"even: "<<even<<"odd: "<<odd<<endl;
    //     if(n%2 != 0 ){
    //       on = on + even + odd -1;
    //     }else{
    //       on = (evenCount%2 == 0) ? on + even + odd -1 :on + even + odd +1;
    //     }
    //     return on;
    // }
};


int main(){
  Solution s;
  // for(int i = 0; i < 10 ; i++){
  //   cout<<"bulb: "<<i<<"on: "<<s.bulbSwitch(i)<<endl;
  // }
  cout<<s.bulbSwitch(9999)<<endl;
  // for(int i = 2 ; i < 10 ; i++){
  //    cout<<s.numberDiv(i)<<endl;
  // }
 
  return 0;
}