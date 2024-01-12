#include <unordered_map>
#include <vector>

using namespace std;

class ParkingSystem {
private:
    //unordered_map<int,int> parkingMap;
    vector<int> parkingVect;

public:
    ParkingSystem(int big, int medium, int small) {
      // parkingMap[1] = big;
      // parkingMap[2] = medium;
      // parkingMap[3] = small;
      parkingVect.push_back(big);
      parkingVect.push_back(medium);
      parkingVect.push_back(small);
      //parkingVect = {big,medium,small};
    }
    
    bool addCar(int carType) {
      //  if(parkingMap[carType]>0){
      //   parkingMap[carType]--;
      //   return true;
      //  }else{
      //   return false;
      //  }
      //return (parkingMap[carType]--)> 0 ?  true : false;
      return (parkingVect[carType-1]--)> 0 ?  true : false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */