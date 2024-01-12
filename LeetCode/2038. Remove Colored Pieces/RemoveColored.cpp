#include <unordered_set>
#include <queue>
#include <string>

using namespace std;

class Solution {
public:

    bool winnerOfGame(string colors) {
        int count = 0;

        for(int i = 1; i < colors.size()-1 ; i++){
          if(colors[i-1] == colors[i] && colors[i] == colors[i+1]){
            if(colors[i] == 'A'){
              count ++;
            }else{
              count --;
            }
          }
        }

        return count > 0;
    }

    bool winnerOfGame(string colors) {
        int countA = 0, countB = 0;
        bool AliceTurn = true;
        //int turns = colors.size();

        for(int i = 1; i < colors.size()-1 ; i++){
          if(colors[i-1] == colors[i] && colors[i] == colors[i+1]){
            if(colors[i] == 'A'){
              countA ++;
            }else{
              countB ++;
            }
          }
        }

        for(int i = 0 ; i < colors.size() ; i++){
          if(AliceTurn){
            if(!countA) return false;
            countA--;
          }else{
            if(!countB) return true;
            countB--;
          }
          AliceTurn = !AliceTurn;
        }

        return !AliceTurn;
    }

    bool winnerOfGame(string colors) {
        // unordered_set<int> idxA;
        // unordered_set<int> idxB;
        queue<int> idxA;
        queue<int> idxB;
        bool AliceTurn = true;
        int turns = colors.size();

        for(int i = 1; i < colors.size()-1 ; i++){
          if(colors[i-1] == colors[i] && colors[i] == colors[i+1]){
            if(colors[i] == 'A'){
              //idxA.insert(i);
              idxA.push(i);
            }else{
              //idxB.insert(i);
              idxB.push(i);
            }
          }
        }

        while(turns-->0){
          if(AliceTurn){
            if(idxA.empty()) return false;
            idxA.pop();
          }else{
            if(idxB.empty()) return true;
            idxB.pop();
          }
          AliceTurn = !AliceTurn;
        }

        return !AliceTurn;
    }
};