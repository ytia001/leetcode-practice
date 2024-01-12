#include <stack>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
      vector<int> res;
      queue<int> q;
      res.push_back(asteroids[0]);
      for(int i = 1; i < asteroids.size() ; i++){
        q.push(asteroids[i]);
      }

      while(!q.empty()){

        if(res.empty()){
          res.push_back(q.front());
          q.pop();
          continue;
        }

        bool movingRight = false;
        bool movingLeft = false;

        int right = q.front();
        if(right < 0) movingLeft = true;

        int left = res.back();
        if(left > 0) movingRight = true;

        if(!movingLeft || !movingRight ){
          res.push_back(right);
          q.pop();
        }
        else if(left + right == 0){
          res.pop_back();
          q.pop();
        }
        else{
          if(abs(left) > abs(right)){
            q.pop();
          }else{
            res.pop_back();
          } 
        }
      }

      return res; 
    }

    vector<int> asteroidCollision(vector<int>& asteroids) {
      vector<int> res;
      res.push_back(asteroids[0]);

      for(int i = 1; i < asteroids.size() ; i++){
        if(res.empty()){
          res.push_back(asteroids[i]);
          continue;
        }

        bool movingRight = false;
        bool movingLeft = false;

        int right = asteroids[i];
        if(right < 0) movingLeft = true;

        int left = res.back();
        if(left > 0) movingRight = true;

        if(!movingLeft || !movingRight ){
          res.push_back(right);
        }
        else if(left + right == 0){
          res.pop_back();
        }
        else{
          if(abs(left) > abs(right)){
            // res.push_back(left);
            continue;
          }else{
            i--;
            res.pop_back();
          } 
        }
      }

      return res; 
    }

     // while(res.size() > 1){
      //   bool movingRight = false;
      //   bool movingLeft = false;

      //   int right = res.back();
      //   if(right < 0) movingLeft = true;
      //   res.pop_back();

      //   int left = res.back();
      //   if(left > 0) movingRight = true;
      //   res.pop_back();

      //   if(!movingLeft || !movingRight ) break;
      //   if((left > 0 && right > 0) || (left < 0 && right < 0)){
      //     res.push_back(left);
      //     res.push_back(right);
      //     break;
      //   }
      //   else if(left + right == 0){
      //     continue;
      //   }
      //   else{
      //     if(abs(left) > abs(right)){
      //       res.push_back(left);
      //     }else{
      //       res.push_back(right);
      //     } 
      //   }
      // }

    vector<int> asteroidCollision(vector<int>& asteroids) {
      vector<int> res;
      int first = asteroids[0];
      int sec = asteroids[1];

      if(first+sec!=0){
        if((first > 0 && sec > 0) || (first < 0 && sec < 0) ){
          res.push_back(first);
          res.push_back(sec);
        }else{
          (abs(first) > abs(sec))? res.push_back(first) : res.push_back(sec);
        }
      }

      for(int i = 2 ; i < asteroids.size() ; i++){
        int currentVal = asteroids[i];
        while(!res.empty()){
          int lastVal = res.back();
          res.pop_back();
          if((lastVal > 0 && currentVal > 0) || (lastVal < 0 && currentVal < 0)){
            res.push_back(lastVal);
            //res.push_back(currentVal);
            break;
          }
          else if(lastVal + currentVal == 0){
            currentVal = 0;
            break;
          }
          else{
            if(abs(currentVal) > abs(lastVal)){
              continue;
            }else{
              res.push_back(lastVal); 
              currentVal = 0;
              break;
            } 
          }

        }
        if(currentVal) res.push_back(currentVal);
      }
      
      return res;
    }
};