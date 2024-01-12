# include <string>
# include <vector>
# include <list>
# include <map>
# include <unordered_map>
# include <algorithm>
# include <queue>

using namespace std;

auto comparator = [](const pair<int,string>& a, const pair<int,string>& b){
   if(a.first != b.first){
    return a.first > b.first;
   }else{
    return a.second < b.second;
   }
};

class FoodRatings {
private:
    unordered_map<string,priority_queue<pair<int,string>,vector<pair<int,string>>,decltype(comparator)>> map;
    unordered_map<string,int> foodRatings;
    
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
      for(int i = 0 ; i < foods.size() ; i++){
        map[cuisines[i]].push({ratings[i],cuisines[i]});
        foodRatings[foods[i]] = ratings[i];
      }
    }
    
    void changeRating(string food, int newRating) {
      foodRatings[food] = newRating;
    }
    
    string highestRated(string cuisine) {
      while(!map[cuisine].empty()){
        auto a = map[cuisine].top();
        if(foodRatings[a.second] == a.first){
          return a.second;
        }else{
          map[cuisine].pop();
        }
      }
      return "";
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */