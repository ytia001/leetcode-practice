#include <string>
#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    // int maxVowels(string s, int k) {
    //   int maxVowel = 0;
    //   int currVowel = 0;
    //   string vowel = "aeiou";
    //   queue<char> q;
    //   for(int i = 0 ; i<k ; i++){
    //     auto loc = vowel.find(s[i]);
    //     if(loc!=string::npos){
    //       currVowel++;
    //     }
    //     q.push(s[i]);
    //   }
    //   if(currVowel>maxVowel){
    //     maxVowel = currVowel;
    //   }
    //   for(int i =k ; i<s.size() ; i++){
    //     auto loc = vowel.find(q.front());
    //     if(loc!=string::npos){
    //       currVowel--;
    //     }
    //     q.pop();
    //     loc = vowel.find(s[i]);
    //     if(loc!=string::npos){
    //       currVowel++;
    //     }
    //     q.push(s[i]);
    //     if(currVowel>maxVowel){
    //     maxVowel = currVowel;
    //     }
    //   }
    //   return maxVowel;
    // }

    int maxVowels(string s, int k) {
      int maxVowel = 0;
      int currVowel = 0;
      string vowel = "aeiou";
      queue<char> q;

      for(int i = 0 ; i<s.size() ; i++){

        if(i<k){
          auto loc = vowel.find(s[i]);
          if(loc!=string::npos){
            currVowel++;
          }
          q.push(s[i]);
        if(currVowel>maxVowel){
          maxVowel = currVowel;
        }
          continue;
        }

        

        auto loc = vowel.find(q.front());
        if(loc!=string::npos){
          currVowel--;
        }
        q.pop();
        loc = vowel.find(s[i]);
        if(loc!=string::npos){
          currVowel++;
        }
        q.push(s[i]);
        if(currVowel>maxVowel){
        maxVowel = currVowel;
        }
      }
      return maxVowel;
    }


    int answer(string s, int k) {
        int vowels[26] = {1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1};
        int max_vow = 0;
        for (auto i = 0, cur_vow = 0; i < s.size(); ++i) {
            cur_vow += vowels[s[i] - 'a'];
            if (i >= k){
                cur_vow -= vowels[s[i - k] - 'a'];
            }
            max_vow = max(max_vow, cur_vow);
        }
        return max_vow;
    
  }
};

int main(){
  Solution s;
  string test = "leetcode";
  std::cout<<s.maxVowels(test,3)<<std::endl;
  return 0 ;
}