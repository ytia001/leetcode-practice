#include <unordered_map>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>

using namespace std;

class MedianFinder {
  priority_queue<int,vector<int>,greater<>> pq1;
  priority_queue<int,vector<int>,less<>> pq2;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
      if(pq1.empty() || pq1.top() >= num){
        pq1.push(num);
      }else{
        pq2.push(num);
      }

      if(pq1.size()-pq2.size()>1){
        pq2.push(pq1.top());
        pq1.pop();
      }else if(pq2.size()-pq1.size()>1){
        pq1.push(pq2.top());
        pq2.pop();
      }
    }
    
    double findMedian() {
      if(pq1.size()==pq2.size()){
        return ((double)pq1.top()+(double)pq2.top())/2;
      }else{
        if(pq1.size()>pq2.size()) return pq1.top();
        return pq2.top();
      }
    }
};


// class MedianFinder {
//    vector<int> container;
// public:
//     MedianFinder() {
        
//     }

//     int search(vector<int>& container,int target){
//       if(container.empty()) return 0;
//       int l = 0;
//       int r = container.size()-1;
//       while(l<=r){
//         int mid = l + (r-l)/2;
//         if(container[mid]>target){
//           r = mid - 1;
//         }else if(container[mid]<target){
//           l = mid + 1;
//         }else{
//           return mid;
//         }
//       }

//       return l;
//     }
    
//     void addNum(int num) {
//       if(container.empty()){ 
//         container.push_back(num);
//         return;
//       }

//       if(num > container[container.size()-1]){
//         container.push_back(num);
//       }else if (num < container[0]){
//         container.insert(container.begin(),num);
//       }else{
//         int idx = search(container,num);
//         container.insert(container.begin()+idx,num);
//       }
//     }
    
//     double findMedian() {
//       double res;
//       bool isOdd = (container.size()%2==0) ? false : true;
//       cout<<container.size()<<endl;
//       isOdd? cout<<"odd"<<endl: cout<<"even"<<endl;
//       int index = container.size()/2;
//       if(isOdd){
//         return (double) container[index];
//       }else{
//         res = ((double)container[index] + container[index-1])/2;
//       }
//       return res;
//     }
// };

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */