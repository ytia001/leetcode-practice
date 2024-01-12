#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    double average(vector<int>& salary) {
        int maxSalary,minSalary;
        double total = 0;
        int count = 0;
        if(salary[0]>salary[1]){
          maxSalary = salary[0];
          minSalary = salary[1];
        }else{
          maxSalary = salary[1];
          minSalary = salary[0];
        }
        for (int i = 2 ; i < salary.size() ; i++){
          if(maxSalary<salary[i]){
            total += maxSalary;
            count ++;
            maxSalary = salary[i];
          }else if(salary[i]<minSalary){
            total += minSalary;
            count ++;
            minSalary = salary[i];
          }else{
            total += salary[i];
            count ++;
          }
        }
        return total/count;
    }
};

int main(){
  Solution s;
  std::vector<int> test = {1400,2020,3000,2939,43248,32498,123,3243,394};
  double result = s.average(test);
  std::cout<<result<<std::endl;
  return 0;
}