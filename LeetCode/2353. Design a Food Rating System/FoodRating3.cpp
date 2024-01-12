# include <string>
# include <vector>
# include <list>
# include <map>
# include <unordered_map>
# include <algorithm>
using namespace std;



class FoodRatings {
private:
    unordered_map<string,map<int,vector<string>>> map;
    unordered_map<string,string> foodCuisine;
    unordered_map<string,int> foodRatings;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
      for(int i = 0 ; i < foods.size() ; i++){
        map[cuisines[i]][ratings[i]].push_back(foods[i]);
        foodCuisine[foods[i]] = cuisines[i];
        foodRatings[foods[i]] = ratings[i];
      }
    }
    
    void changeRating(string food, int newRating) {
      vector<string> foods = map[foodCuisine[food]][foodRatings[food]];
      auto itr = find(foods.begin(),foods.end(),food);
      if(itr != foods.end()){
        foods.erase(itr);
      }
      map[foodCuisine[food]][newRating].push_back(food);
      foodRatings[food] = newRating;
    }
    
    string highestRated(string cuisine) {
      vector<string> foodVect = map[cuisine].rbegin() -> second;
      sort(foodVect.begin(),foodVect.end());
      return foodVect.front();
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */