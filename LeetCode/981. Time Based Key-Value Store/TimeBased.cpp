#include <string>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class TimeMap {
public:
    unordered_map<string,unordered_map<int,string>> mp;
    unordered_map<string,vector<int>> timeline;
    int search(string key , int timestamp){
      int l = 0;
      int r = timeline[key].size()-1;
      while(l<r){
        int mid = l + (r-l+1)/2;
        if(timestamp < timeline[key][mid]){
          r = mid - 1;
        }else{
          l = mid;
        }
      }
      return timeline[key][l];
    }

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
      timeline[key].push_back(timestamp);
      mp[key][timestamp]=value;
    }
    
    string get(string key, int timestamp) {
      if(!mp.count(key)) return "";
      return (search(key,timestamp) <= timestamp) ?  mp[key][search(key,timestamp)] : "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */