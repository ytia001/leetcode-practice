# include <string>
# include <queue>
# include <iostream>

using namespace std;

auto comparator = [] ( const pair<char,int>& a, const pair<char,int>& b){
  return a.second > b.second;
};

class Solution {
public:

    int getLengthOfOptimalCompression(string s, int k) {
    //    if(k == 0) return s.size();
      if(s.size() <= k) return 0;

      int count = 1; 
      char currentChar = s[0];

      string encoded ="";
      priority_queue<pair<char,int>,vector<pair<char,int>>,decltype(comparator)> pq;

      for(int i = 1 ; i < s.size() ; i++){
        if(s[i] != currentChar){
          encoded += currentChar + (count > 1 ? to_string(count) : "");
          pq.push({currentChar, count});
          currentChar = s[i];
          count = 1;
        }else{
          count++;
        }
      }
      encoded += currentChar + (count > 1 ? to_string(count) : "");
      pq.push({currentChar, count});
      int res = encoded.size();

      while(k > 0){
        auto next = pq.top(); 
        if(next.second > k) {
          break;
        }else{
          pq.pop();
          k -= next.second;
          res -= next.second == 1 ? 1 : 2;
        }
      }
      return res;
    }
};