

class Solution {
public:
    int totalMoney(int n) {
      int a = 1;
      int total = 0;
      while(n){
        int terms = n%7;
        total += (terms,a++);
        n -= terms;
      }  
      return total;
    }

    int sum(int terms , int a){
      return (terms/2)*(2*a + (terms-1));
    }
};