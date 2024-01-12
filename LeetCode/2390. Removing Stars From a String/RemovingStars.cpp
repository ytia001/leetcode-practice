#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
     string removeStars(string s) {
       std::size_t found = s.find('*');
        while(found!=string::npos){
          s.erase(found-1,2);
          found = s.find('*');
        }
        return s;
    }


    string removeStarsTest(string s) {
        stack<int> indexContainer;
        int containerFinalSize = 0;
        string finalString = "";
        
        for (int i = 0 ; i<s.size() ; i++){
          if(s[i] =='*'){
            //cout<<"pop out: "<<indexContainer.top()<<endl;
            indexContainer.pop();
            continue;
          }
          //cout<<"put in: "<<i<<endl;
          indexContainer.push(i);
        }
        
        containerFinalSize =  indexContainer.size();

        for(int i = 0 ; i < containerFinalSize ; i++){
          int idx = indexContainer.top();
          //cout<<"idx: "<<idx<<endl;
          indexContainer.pop();
          finalString = s[idx] + finalString;
        }
        return finalString;
    }
};

int main(){
  Solution s;
  string test = "leet**cod*e";
  cout<<s.removeStars(test)<<endl;
  return 0;
}