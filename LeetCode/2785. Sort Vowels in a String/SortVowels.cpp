# include <string>
# include <vector>
# include <algorithm>

using namespace std;

class Solution {
public:

    string sortVowels(string s) {
      string temp;
      vector<char> check = {'A','E','I','O','U','a','e','i','o','u'};

      for(int i = 0 ; i < s.size() ; i++){
        if(find(check.begin(),check.end(),s[i]) != check.end()){
          temp += s[i];
          s[i] = '0';
        }
      }

      sort(temp.rbegin(),temp.rend());

      for(int i = 0 ; i < s.size() ; i++){
        if(s[i] == '0'){
          s[i] = temp.back();
          temp.pop_back();
        }
      }

      return s;
    } 


    string sortVowels(string s) {
      vector<char> check = {'A','E','I','O','U','a','e','i','o','u'};
      vector<int> store(10,0);

      for(int i = 0 ; i < s.size() ; i++){
        for(int c = 0 ; c < check.size() ; c++){
          if(check[c] == s[i]){
            s[i] = '0';
            store[c]++;
          }
        }
      }

      for(int i = 0 ; i < s.size() ; i++){
        if(s[i] == '0'){
          for(int c = 0 ; c < store.size() ; c++){
            if(store[c] != 0 ){
              s[i] = check[c];
              break;
            }
          }
        }
      }

      return s;
    } 
};