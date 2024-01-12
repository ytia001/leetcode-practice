# include <string>
# include <vector>
# include <list>
# include <unordered_map>

using namespace std;

struct node{
  string food;
  int rating;
  node* next;
  node* pre;

  node(int val): rating(val),food(NULL) {}
  node(int val, string food): rating(val), food(food){}
};


void deleteNode(node* n){
  n->pre->next = n->next;
  n->next->pre = n->pre;
}

void insertNode(node* n , node* target){
  target->next = n->next;
  n->next->pre = target;
  n -> next = target;
  target->pre = n;
}

// void initialize(node* start, node* end){
//   start->next = end;
//   end->pre = start;
// }


class FoodRatings {
private:
    unordered_map<string,node*> dict;
    unordered_map<string,pair<node*,node*>> map;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
      int size = foods.size();
      for(int i = 0 ; i < size ; i++){
        if(map.count(cuisines[i])){
          node* start = map[cuisines[i]].first;
          node* end = map[cuisines[i]].second;
          node* newNode = new node(ratings[i],foods[i]);

          while(start->next != end){
            if(start->next->rating < ratings[i] || (ratings[i] == start->next->rating) && (foods[i] < start->next->food)){
              start = start->next;
            }else{
              break;
            }
          }

          insertNode(start,newNode);
          dict[foods[i]] = newNode;
        }else{
          node* start = new node(0);
          node* end = new node(0);
          start->next = end;
          end->pre = start;

          node* newNode = new node(ratings[i],foods[i]);
          insertNode(start,newNode);
          map[cuisines[i]] = {start,end};
          dict[foods[i]] = newNode;
        }
      }
    }
    
    void changeRating(string food, int newRating) {
      node* newPtr = dict[food];
      while(newPtr->next->rating!= 0 && newPtr->rating < newRating || ){
        while(newPtr->next->rating!= 0){

        }
      }
      
      while(newPtr->next->rating!= 0){
        
      }

      delete(ptr);
    }
    
    string highestRated(string cuisine) {
      node* end = map[cuisine].second;
      return end->pre->food;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */