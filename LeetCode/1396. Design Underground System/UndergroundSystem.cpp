#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class UndergroundSystem {
private:
    unordered_map<int,pair<string,double>> ongoingMap;
    unordered_map<string,unordered_map<string,pair<int,double>>> stationMap;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
      ongoingMap[id] = {stationName,(double)t};
    }
    
    void checkOut(int id, string stationName, int t) {
      stationMap[ongoingMap[id].first][stationName].first += 1;
      stationMap[ongoingMap[id].first][stationName].second += (t-ongoingMap[id].second);
      ongoingMap.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        return stationMap[startStation][endStation].second/stationMap[startStation][endStation].first;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */