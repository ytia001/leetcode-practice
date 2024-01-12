#include "ValidPerfectSquare.hpp"

//solution 
//  bool isPerfectSquare(int num) {
//         int i=1;
//         while(num>0){
//             num -= i;      //Subtracting odd number from num and updating num
//             i +=2;         // Updating i to the next odd number
//             if(!num) return true;
//         }
//         return false;
//     }

bool Solution::isPerfectSquare(int num){
  int left = 0;
  int right = 46341;

  while ( left < right){
    int mid = left + (right - left)/2;
    
    unsigned int currentSquare = mid * mid;
    
      // std::cout<< left <<"::"<<right<< std::endl;
      // std::cout<< currentSquare << std::endl; 
    if ( currentSquare == num){
      return true;
    }
    else if ( currentSquare > num){
      right = mid;
    }else{
      left = mid + 1;
    }
   
  }
   
  return false;
  
}

int main(){
  Solution s1;
  s1.isPerfectSquare(2147395600)? std::cout<< "True"<< std::endl : std::cout<< "False"<< std::endl;
  return 0;
}