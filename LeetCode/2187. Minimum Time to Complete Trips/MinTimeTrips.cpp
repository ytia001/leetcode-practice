#include"MinTimeTrips.hpp"

// Solution
// #define ll long long 
// class Solution {
// public:
//     long long minimumTime(vector<int>& time, int totalTrips) {
//         ll start = 1;
//         ll end = 1e14;
//         while(start <= end){
//             ll trip = 0;
//             ll mid = start + (end - start)/2;
//             for(int i=0;i<time.size();i++)
//                 trip += mid / time[i];
//             if(trip < totalTrips){
//                 start = mid + 1;
//             }
//             else 
//                 end = mid - 1;
//         }
//         return start;
//     }
// };

long long Solution::minimumTime(std::vector<int>& time, int totalTrips){
  std::sort(time.begin(),time.end());
  if(time[0]==1 && time[time.size()-1]==1){
    if(time[0]==time[time.size()-1] && time.size()>1){
      return totalTrips/(time.size()*time[0]);
    }
  }
  long long left = static_cast<long long>(time[0]);
  long long right = static_cast<long long>(time[0]) * static_cast<long long>(totalTrips);
  while ( left < right){
    long long mid = left + (right-left)/2;
    //std::cout<<"mid: "<<mid<<std::endl;
    std::vector<long long> copy(time.begin(),time.end());
    std::transform(copy.begin(),copy.end(),copy.begin(),[mid](long long x){return mid/x;});
    long long currTotalTrips = std::accumulate(copy.begin(),copy.end(),0);
    //std::cout<<currTotalTrips<<std::endl;
    if (currTotalTrips < totalTrips){
      left = mid +1;
    }else{
      right = mid;
    }
  }
  return left;
}


int main(){
  std::vector<int> test = {2,2,2};
  Solution s1;
  std::cout<<s1.minimumTime(test,4) << std::endl;
  //std::cout<<s1.currTotalTime(test,2,0) << std::endl;
  return 0;
}

// THIRD TRY
// long long Solution::currTotalTime(std::vector<int>& time,int totalTrips,int startIndex){
//   std::sort(time.begin(),time.end());
//   long long left = startIndex;
//   long long right = time.size()-1;
//   while ( left < right ){ 
//     long long mid = left + (right-left)/2;
//     std::vector<int> copy = time;
//     long long totalTime = std::accumulate(time.begin()+startIndex,time.begin()+mid+1,0); 
//     std::cout<<"totalTime: "<<totalTime<<std::endl;
//     std::transform(copy.begin(),copy.end(),copy.begin(),[totalTime](int x){return totalTime/x;});
//     long long currTotalTrips = std::accumulate(copy.begin(),copy.end(),0);
//     if ( currTotalTrips == totalTrips){
//       return totalTime;
//     }else if ( currTotalTrips < totalTrips){
//       left = mid +1;
//     }else{
//       right = mid;
//     }
//   }
//   std::vector<int> copy = time;
//   long long totalTime = std::accumulate(time.begin()+startIndex,time.begin()+left+1,0); 
//   std::cout<<"totalTime: "<<totalTime<<std::endl;
//   std::transform(copy.begin(),copy.end(),copy.begin(),[totalTime](int x){return totalTime/x;});
//   long long currTotalTrips = std::accumulate(copy.begin(),copy.end(),0);
//   if(currTotalTrips < totalTrips) return 0;
//   return totalTime;
// }
// long long Solution::minimumTime(std::vector<int>& time, int totalTrips){
//   std::sort(time.begin(),time.end());
//   long long minTime = INT_MAX;
//   for (int i = 0 ; i<time.size(); i++){
//     long long totalTime = currTotalTime(time,totalTrips,i);
//     if(totalTime!=0 &&totalTime < minTime ){
//       minTime = totalTime;
//     }
//   }
//   if(minTime == INT_MAX) return totalTrips;
//   return minTime;
// }

// Second TRY
// long long Solution::minimumTime(std::vector<int>& time, int totalTrips){
//   std::sort(time.begin(),time.end());
//   long long  left = 0;
//   long long right = time.size()-1;
//   long long fixedPoint = time.size()-1;
//     while ( left < right ){
//     long long mid = left + (right-left)/2;
//     std::vector<int> copy = time;
//     long long totalTime = std::accumulate(time.begin()+mid,time.begin()+fixedPoint+1,0); 
//     std::transform(copy.begin(),copy.end(),copy.begin(),[totalTime](int x){return totalTime/x;});
//     long long currTotalTrips = std::accumulate(copy.begin(),copy.end(),0);
//     if ( currTotalTrips == totalTrips){
//       return totalTime;
//     }else if ( currTotalTrips < totalTrips){
//       right = mid;
//     }else{
//       left = mid +1;
//     }
//   }
//   std::vector<int> copy = time;
//   long long totalTime = std::accumulate(time.begin()+left,time.begin()+fixedPoint+1,0); 
//   std::transform(copy.begin(),copy.end(),copy.begin(),[totalTime](int x){return totalTime/x;});
//   long long currTotalTrips = std::accumulate(copy.begin(),copy.end(),0);
//   if(currTotalTrips < totalTrips) return 0;
//   return totalTime;
// }

// FIRST TRY
// long long Solution::minimumTime(std::vector<int>& time, int totalTrips){
//   std::sort(time.begin(),time.end());
//   long long  left = 0;
//   long long right = time.size()-1;
//   while ( left < right ){
//     long long mid = left + (right-left)/2;
//     long long currentTrips = (mid*time[mid]) + 1;
//     // std::cout<<"time[mid]: "<<time[mid]<<"time[left]: "<<time[left]<<std::endl;
//     // long long oneTruckMaxTrip = time[mid]/time[left];
//     // std::cout<<"mid: "<<mid<<std::endl;
//     // long long currentTrips = ((mid-left)*oneTruckMaxTrip) + 1;
//     // std::cout<<"oneTruckMaxTrip: "<<oneTruckMaxTrip<<std::endl;
//     std::cout<<"CurrentTrips: "<<currentTrips<<std::endl;
//     if(currentTrips > totalTrips){
//       right = mid;
//     }else{
//       left = mid + 1;
//     }
//   }
//   std::vector<int> finalTimeVect(time.begin(),time.begin()+left);
//   std::transform(finalTimeVect.begin(),finalTimeVect.end(),finalTimeVect.begin(),[left,&time](int x){return time[left]/x;});
//   for (auto i :finalTimeVect) std::cout<< i << "  ";
//   std::cout<<"\n";
//   long long realTotalTrips = std::accumulate(finalTimeVect.begin(),finalTimeVect.end(),0) + 1;
//   std::cout<<"Real Total Trips: "<<realTotalTrips<<std::endl;
//   if(realTotalTrips < totalTrips) return 0;
//   return time[left];
// }

