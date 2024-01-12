#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:

    string removeDuplicateLetters(string s) {
      string res;
      vector<int> asciiIndex(26,INT_MAX);
      vector<int> alphaPresent(26,-1);
      alphaPresent[s[0]-'a'] = 0;
      asciiIndex[0] = min(asciiIndex[0],s[0]-'a');  
      //minAscii[s[0]-'a'] = min(minAscii[s[0]-'a'],s[0]-'a');

      for(int i = 1 ; i < s.size() ; i++ ){
        if(alphaPresent[s[i]-'a'] >= 0){
          //asciiIndex[i] = min(asciiIndex[i-1],s[i]-'a'); 
          if(s[i]-'a' < asciiIndex[i-1]){
            s[alphaPresent[s[i]-'a']] = ' ';
            alphaPresent[s[i]-'a'] = i;
            asciiIndex[i] = min(asciiIndex[i-1],s[i]-'a');
          }else{
            s[i] = ' ';
          }
        }else{
           alphaPresent[s[i]-'a'] = i;
           asciiIndex[i] = min(asciiIndex[i-1],s[i]-'a'); 
        }
      }

      for(char& c: s){
        if(c == ' ') continue;
        res += c;
      }

      return res;
    }

    string removeDuplicateLetters(string s) {
      string res;
      vector<int> asciiIndex(26,INT_MAX);
      vector<int> alphaPresent(26,-1);
      alphaPresent[s[0]-'a'] = 0;
      asciiIndex[0] = min(asciiIndex[0],s[0]-'a');  
      //minAscii[s[0]-'a'] = min(minAscii[s[0]-'a'],s[0]-'a');

      for(int i = 1 ; i < s.size() ; i++ ){
        //cout<<alphaVect[s[i]-'a']<<endl;
        if(alphaPresent[s[i]-'a'] >= 0){
          asciiIndex[i] = min(asciiIndex[i-1],s[i]-'a'); 
          if(asciiIndex[i] < asciiIndex[alphaPresent[s[i]-'a']]){
            //cout<<"alphaVect[s[i]-'a']-1: "<<alphaVect[s[i]-'a']-1<<endl;
            s[alphaPresent[s[i]-'a']] = ' ';
            alphaPresent[s[i]-'a'] = i;
            //asciiIndex[i] = min(asciiIndex[i-1],s[i]-'a'); 
          }else{
            s[i] = ' ';
          }
        }else{
           alphaPresent[s[i]-'a'] = i;
           asciiIndex[i] = min(asciiIndex[i-1],s[i]-'a'); 
        }
      }

      for(char& c: s){
        if(c == ' ') continue;
        res += c;
      }

      return res;
    }


    string removeDuplicateLetters(string s) {
    string res;
      vector<int> alphaVect(26,0);
      //vector<int> minAscii(26,INT_MAX);
      alphaVect[s[0]-'a'] = 1;  // index 0 taken as 1 for comparison of next char
      //minAscii[s[0]-'a'] = min(minAscii[s[0]-'a'],s[0]-'a');

      for(int i = 1 ; i < s.size() ; i++ ){
        //cout<<alphaVect[s[i]-'a']<<endl;
        if(alphaVect[s[i]-'a']){
          if(s[i] > s[alphaVect[s[i]-'a']]){
            //cout<<"alphaVect[s[i]-'a']-1: "<<alphaVect[s[i]-'a']-1<<endl;
            s[alphaVect[s[i]-'a']-1] = ' ';
            alphaVect[s[i]-'a'] = i + 1;
          }else{
            s[i] = ' ';
          }
        }else{
           alphaVect[s[i]-'a'] = i + 1; 
        }
      }

      for(char& c: s){
        if(c == ' ') continue;
        res += c;
      }

      return res;
    }
};