#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:

    int longestPalindrome(string s) {
       unordered_set<char> alphabet;
       int res = 0;
       for(auto& i : s){
        if(alphabet.count(i)){
          alphabet.erase(i);
          res += 2;
          continue;
        }
        alphabet.insert(i);
       }
       if(!alphabet.empty()) return res+1;
       return res; 
    }

    int longestPalindrome(string s) {
       int size = s.size();
       if(size<=1) return size;
       unordered_map<char,int> alphabet;
       int res = 0;
       for(auto i : s){
        if(alphabet[i]){
          res += 2;
          alphabet[i]--;
        }else{
          alphabet[i]++;
        }
       }
       if(size-res) return res+1;
       return res; 
    }


    int longestPalindrome(string s) {
       if(s.size()<=1) return s.size();
       vector<int> alphabet(52,0);
       int res = 0;
       for(auto i : s){
        int asciiVal =  (i-'A' > 25 )? (i - 'a') + 26 : (i-'A');
        if(alphabet[asciiVal]==1){
          res += 2;
          alphabet[asciiVal]--;
        }else{
          alphabet[asciiVal]++;
        }
       }
       if(s.size()-res) return res+1;
       return res; 
    }
};

int main(){

  Solution s;
  cout<<s.longestPalindrome("aaaAaaaa")<<endl;
  return 0;
}