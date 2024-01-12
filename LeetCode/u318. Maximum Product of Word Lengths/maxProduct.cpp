#include "maxProduct.hpp"

  bool comparator(string a , string b){
      return a.length() <= b.length();
    }

int maxLengthOneString(int currIndex, vector<string>& words){
    

  }

 int maxProduct(vector<string>& words){
    unordered_set<char> charsUsed;
    unordered_map<string,unordered_set<char>> stringToSet;
    string allString = "";
    for(string s : words) allString += s;
    for ( int i = 97 ; i < 123 ; i++){
      size_t found = allString.find((char) i);
      if(found!= string::npos){
        charsUsed.insert((char)i);
      }else{
        continue;
      }
    }
    for (string s : words){
      unordered_set<char> charSet;
      vector<char> inputVect = s.c_str();
      charSet.insert();
    }
 }





 int main(){

  Solution s;
  // vector<string> test ={"a","ab","abc","abcd","abcde","abcdef","abcdefg",
  // "abcdefgh","abcdefghi","abcdefghij","abcdefghijk","abcdefghijkl","abcdefghijklm","nopqrstuvwxyz",
  // "mnopqrstuvwxyz","lmnopqrstuvwxyz","klmnopqrstuvwxyz","jklmnopqrstuvwxyz","ijklmnopqrstuvwxyz","hijklmnopqrstuvwxyz",
  // "ghijklmnopqrstuvwxyz","fghijklmnopqrstuvwxyz","efghijklmnopqrstuvwxyz","defghijklmnopqrstuvwxyz","cdefghijklmnopqrstuvwxyz",
  // "bcdefghijklmnopqrstuvwxyz"};
  // int result = maxLengthOneString(0, test);
  // cout<<result<<endl;
  // cout<<maxProduct(test)<<endl;
  vector<string> test ={"a","b","ab","fd","r"};
  // vector<string> copy(begin(test),end(test),)
  unordered_set<string> testSet;
  testSet.insert({"a","a","b","f","e","f"});
  //testSet.erase({"z","f"});
  for (auto o : testSet) cout<<o<<endl;
  return 0;
 }

// Draft2 ONLY WORK FOR TEST CASES WITH SMALL LENGTH
// bool comparator(string a , string b){
//       return a.length() <= b.length();
//     }
// int maxLengthOneString(int currIndex, vector<string>& words){
//     string currString = words[currIndex];
//     vector<string> copy(begin(words),end(words));
//     copy.erase(begin(copy)+currIndex);  
//     vector<char> appearChars;

//     //string checkList = "abcdefghijklmnopqrstuvwxyz";
//     for ( int i = 97 ; i < 123 ; i++){
//       size_t found = currString.find((char) i);
//       if(found!= string::npos){
//         appearChars.push_back((char)i);
//       }else{
//         continue;
//       }
//     }
//     transform(begin(copy),end(copy),begin(copy),[appearChars](string inputString){
//       for(char c : appearChars){
//         if(inputString.find(c)!= string::npos){
//           return string("");
//         }
//       }
//           return inputString;
//     });

//     sort(begin(copy),end(copy),comparator);
//     int maxLength = copy[copy.size()-1].size()*(currString.size());
  
//     if(!maxLength) return 0;
//     return maxLength;

//   }
//  int maxProduct(vector<string>& words){
//     int overallMaxLength = 0;
//     int size = words.size();
//     for(int i = 0 ; i < size ; i++){

//       int currMaxLength = maxLengthOneString(size-1-i,words);
//       if(currMaxLength > overallMaxLength){
//         overallMaxLength = currMaxLength;
//       }
//       // cout<<overallMaxLength<<endl;
//     }
//     return overallMaxLength;
//  }



// Draft
 //  int maxProduct(vector<string>& words){
//     sort(begin(words),end(words),comparator);
//     // for(string out : words){
//     //   cout<<out<<endl;
//     // }
//     int size = words.size();
//     string stringRight = words[size-1];
//     string stringLeft = words[size-2];
//     // for ( int i = 0 ; i < size - 2 ; i++){
//     //   if( checkDiff(stringRight,stringLeft) ){

//     //   }else{
//     //     stringRight
//     //   }
//     // }

//     return 0;
//  }

//  unordered_map<char,string> filter(vector<string>& words){
//     unordered_map<char,string> mapCharString;
//     for ( string s : words){

//     }
//  }