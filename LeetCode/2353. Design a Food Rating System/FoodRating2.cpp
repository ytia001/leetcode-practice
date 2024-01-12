# include <string>
# include <vector>
# include <list>
# include <unordered_map>

using namespace std;

bool compare(const pair<string,int>& a , const pair<string,int>& b){
   if(a.second != b.second){
    return a.second < b.second;
   }else{
    return a.first > b.first;
   }
}

class FoodRatings {
private:
    unordered_map<string,list<pair<string,int>>::iterator> dict;
    unordered_map<string,list<pair<string,int>>> map;
    unordered_map<string,string> foodToCuisine;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
      for(int i = 0 ; i < foods.size() ; i++){
        if(map.count(cuisines[i])){
          map[cuisines[i]].push_front({foods[i],ratings[i]});
          // dict[foods[i]] = map[cuisines[i]].begin();
        }else{
          list<pair<string,int>> lst;
          lst.push_front({foods[i],ratings[i]});
          map[cuisines[i]] = lst;
          // dict[foods[i]] = map[cuisines[i]].begin();
        }
        dict[foods[i]] = map[cuisines[i]].begin();
        foodToCuisine[foods[i]] = cuisines[i];
      }

      for(auto& cuisine : map){
        cuisine.second.sort(compare);
      }
    }
    
    void changeRating(string food, int newRating) {
      dict[food] ->second = newRating;
      map[foodToCuisine[food]].sort(compare);
    }
    
    string highestRated(string cuisine) {
      return map[cuisine].back().first;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */