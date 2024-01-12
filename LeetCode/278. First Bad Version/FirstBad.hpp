class Solution {
public:
    int firstBadVersion(int n) {
        if(n==1) return isBadVersion(n);
        int left = 0;
        int right = n-1;
        while (left < right){
          int mid = left + (right-left)/2;
          if(isBadVersion(mid)){
            right = mid;
          }else{
            left = mid + 1;
          }
        }
        return left;
    }
};