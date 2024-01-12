#include <string>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> mp;
    
    int search(string key , int timestamp){
      int l = 0;
      int r = mp[key].size()-1;
      while(l<r){
        int mid = l + (r-l+1)/2;
        if(timestamp < mp[key][mid].first){
          r = mid - 1;
        }else{
          l = mid;
        }
      }
      //return mp[key][l].first;
      return l;
    }

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
      mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
      if(!mp.count(key)) return "";
      return (mp[key][search(key,timestamp)].first <= timestamp) ?  mp[key][search(key,timestamp)].second : "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */