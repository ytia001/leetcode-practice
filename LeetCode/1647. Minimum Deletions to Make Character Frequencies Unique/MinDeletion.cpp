#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:

    int minDeletions(string s) {
      int res = 0;
      unordered_set<int> countSet;
      vector<int> vect(26,0);

      for(char& ch : s){
        vect[ch-'a']++;
      }

      for(int charCount : vect){
        while(charCount !=0 && countSet.count(charCount)){
          --charCount;
          res++;
        }
        if(charCount) countSet.insert(charCount);
      }
      
      return res;
    }
    

    int minDeletions(string s) {
      int res = 0;
      unordered_set<int> countSet;
      unordered_map<char,int> mp;

      for(char& ch : s){
        mp[ch]++;
      }

      for(auto&[ch,charCount] : mp){
        while(countSet.count(charCount)){
          --charCount;
          res++;
        }
        if(charCount) countSet.insert(charCount);
      }
      
      return res;
    }


    void place (int& res, unordered_set<int>& countSet, int currentCount){
      while(countSet.count(currentCount)){
        --currentCount;
        res++;
      }
      countSet.insert(currentCount);
      return;
    }

    int minDeletions(string s) {
      int res = 0;
      unordered_set<int> countSet;
      sort(s.begin(),s.end());

      int currentCount = 0;
      char currentChar;
      for(char& ch : s){
        if(currentChar != ch){
          place(res,countSet,currentCount);
          currentChar = ch;
          currentCount = 1;
        }else{
          currentCount++;
        }
      }
      place(res,countSet,currentCount);
      return res;
    }
};