#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    string reformatDate(string date) {
      unordered_map<string,string> monthVect = {{"Jan","01"},{"Feb","02"},{"Mar","03"},{"Apr","04"},{"May","05"},{"Jun","06"},{"Jul","07"},{"Aug","08"},{"Sep","09"},{"Oct","10"},{"Nov","11"},{"Dec","12"}};


      string day;
      int i = 0;
      while(date[i] !=' '){
        if(!(date[i] - '0' >= 10) ) day += string(1,date[i]);
        i++;
      }
      day = day.size() == 1? "0"+day : day;

      int j = i + 1;
      string month;
      while(date[j] !=' '){
        month += string(1,date[j]);
        j++;
      }
      
      int k = j + 1;
      string year = date.substr(k);

      return year+"-"+monthVect[month]+"-"+day;
    }
};