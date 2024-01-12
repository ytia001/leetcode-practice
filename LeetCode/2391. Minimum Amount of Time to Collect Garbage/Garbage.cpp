#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
       int sG , sP , sM;
       int total = 0;


       for(int i = 0 ; i < garbage.size() ; i++){
        total += garbage[i].size();

        for(char& c : garbage[i]){
          if(c == 'G'){
            total += sG;
            sG = 0;
          }
          else if(c == 'P'){
            total += sP;
            sP = 0;
          }
          else if (c == 'M'){
            total += sM;
            sM = 0;
          }
        }

        if(i<travel.size()){
          sG += travel[i];
          sP += travel[i];
          sM += travel[i];
        }
       }

       return total; 
    }
};