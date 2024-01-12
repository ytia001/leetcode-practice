#include "LemonadeChange.hpp"

//solution
// int lemonadeChange(vector<int> bills) {
//         int five = 0, ten = 0;
//         for (int i : bills) {
//             if (i == 5) five++;
//             else if (i == 10) five--, ten++;
//             else if (ten > 0) ten--, five--;
//             else five -= 3;
//             if (five < 0) return false;
//         }
//         return true;
//     }

bool Solution::lemonadeChange(std::vector<int>& bills){
  int fiveTotal = 0;
  int tenTotal = 0;
  int twentyTotal = 0;
  for (int i = 0; i < bills.size(); i++){
    if(bills[i]==5){
      fiveTotal++;
    }
    else if (bills[i] == 10){
      fiveTotal--;
      if(fiveTotal>=0){
        tenTotal++;
      }
      else{
        return false;
      }
    }
    else if( bills[i] == 20){
      if(fiveTotal>=1 && tenTotal>=1){
        fiveTotal--;
        tenTotal--;
      }else{
        fiveTotal -= 3;
      }
      if(fiveTotal>=0 && tenTotal>=0){
        twentyTotal++;
      }else{
        return false;
      }
    }
  }
  std::cout<<fiveTotal<<std::endl;
  std::cout<<tenTotal<<std::endl;
  std::cout<<twentyTotal<<std::endl;
  return true;
}

// bool Solution::lemonadeChange(std::vector<int>& bills){
//   std::unordered_map<int,int> billsToCount;
//   for(int i:bills){
//     billsToCount[i]++;
//   }
//   billsToCount[5] = billsToCount[5] - billsToCount[10] - billsToCount[20];
//   billsToCount[10] = billsToCount[10] - billsToCount[20];
//   if(billsToCount[5]>=0 && billsToCount[10] >= 0 && billsToCount[20]>=0 ){
//     return true;
//   }
//   else{
//     return false;
//   }
// }

// bool Solution::lemonadeChange(std::vector<int>& bills){
//   int fiveTotal = 0;
//   int tenTotal = 0;
//   int twentyTotal = 0;
//   for (int i = 0; i < bills.size(); i++){
//     if(bills[i]==5){
//       fiveTotal++;
//     }else if (bills[i] == 10){
//       fiveTotal--;
//       // if(fiveTotal>=0){
//       //   tenTotal++;
//       // }
//       tenTotal++;
//     }else if( bills[i] == 20){
//       fiveTotal--;
//       tenTotal--;
//       twentyTotal++;
//     }
//   }
//   std::cout<<fiveTotal<<std::endl;
//   std::cout<<tenTotal<<std::endl;
//   std::cout<<twentyTotal<<std::endl;
//   if(fiveTotal>=0 && tenTotal>=0 && twentyTotal>=0 ) return true;
//   return false;
// }

int main(){
  Solution s1;
  std::vector<int> test = {5,5,5,10,20};
  std::cout<<s1.lemonadeChange(test)<<std::endl;
  return 0;
}