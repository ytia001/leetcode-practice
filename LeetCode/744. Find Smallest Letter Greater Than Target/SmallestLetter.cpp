#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
      char res = letters[0];
      int l = 0;
      int r = letters.size()-1;
      while(l<r){
        int mid = l + (r-l)/2;
        if(letters[mid]-target<=0){
          l = mid+1;
        }else{
          r = mid;
        }
      }
      if(letters[l]-target>0){
        res = letters[l];
      }
      return res;
    }
};