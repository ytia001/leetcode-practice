#include <vector>

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
      if ( arr.size() < 3 ) return -1;

      int l = 0;
      int r = arr.size()-1;

      while(l<r){
        int mid = l + (r-l)/2;
        if(arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1] ){
          return mid;
        }
        else if(arr[mid-1]<arr[mid] && arr[mid]<arr[mid+1]){
          l = mid;
        }else{
          r = mid;
        }
      }

      return l;

    }
};