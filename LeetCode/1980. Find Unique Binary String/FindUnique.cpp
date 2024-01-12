#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string convert(int input, int n){
      int carry = input;
      string output;
      while(n-- > 0){
        output = output + to_string(carry%2);
        carry /= 2;
      }

      return output;
    }

    string findDifferentBinaryString(vector<string>& nums) {
      unordered_set<string> group(nums.begin(),nums.end());
      int n = nums.size();
      for(int i = 0 ; i < pow(2,nums.size()) ; i++){
        if(!group.count(convert(i,n))){
          return convert(i,n);
        }
      }

      return "";
    }
};