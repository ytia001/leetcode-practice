#include <unordered_set>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:

    string replaceWords(vector<string>& dictionary, string sentence) {
      unordered_set<string> rootSet(dictionary.begin(),dictionary.end());
      string res;
      bool skipChar = false;
      string currentString;
      for(int i = 0 ; i < sentence.size(); i++){
        if(sentence[i]!=' '){
          if(skipChar) continue;
          currentString += sentence[i];
          if( rootSet.count(currentString) ){
            skipChar = true;
          }
        }else if(sentence[i]==' '){
          skipChar = false;
          res += currentString + " ";
          currentString = "";
        }
      }
      return res+currentString;
    }


    string replaceWordTest(string word,unordered_set<string>& rootSet){
      string currentRoot;
      for(int i = 0; i < word.size() ; i++){
        currentRoot += word[i];
        if(rootSet.count(currentRoot)){
          return currentRoot;
        }
      }
      return word;
    }

    string replaceWordsTest(vector<string>& dictionary, string sentence) {
      unordered_set<string> rootSet(dictionary.begin(),dictionary.end());
      string res;
      string currentString;
      for(int i = 0 ; i < sentence.size(); i++){
        if(sentence[i]!=' '){
          currentString += sentence[i];
        }else{
          res +=" ";
        }
     
        if(sentence[i+1]==' ' || i+1==sentence.size()){
          res += replaceWordTest(currentString,rootSet);
          currentString = "";
        }
      }
      return res;
    }
};

int main(){
  Solution solution;
  vector<string> dictionary = {"a","b","c"};
  string sentence = "abc";
  cout<<sentence.size()<<endl;
  cout<<solution.replaceWordsTest(dictionary,sentence)<<endl;
  return 0;
}