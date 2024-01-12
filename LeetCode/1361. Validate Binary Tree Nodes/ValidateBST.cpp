#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:

    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
      vector<int> con(n,-1);
      vector<pair<int,int>> out(n,pair<int,int>(-1,-1));
      queue<int> q;
      int total = 0;

      for(int i = 0 ; i < n ; i ++){
        if(leftChild[i] != -1) {
          if(con[leftChild[i]] != -1) return false;
          con[leftChild[i]] = i;
          out[i].first == -1 ? out[i].first = leftChild[i] : out[i].second = leftChild[i];
        }
        if(rightChild[i] != -1) {
          if(con[rightChild[i]] != -1) return false;
          con[rightChild[i]] = i;
          out[i].first == -1 ? out[i].first = rightChild[i] : out[i].second = rightChild[i];
        }
      }

      for(int i = 0 ; i < con.size() ; i++){
        if(con[i]==-1) {
         q.push(i);
         total++; 
        }
      }

      if(q.size() != 1) return false;
      while(!q.empty()){
        int node = q.front(); q.pop();
        auto [left,right] = out[node] ;
        if(left!= -1 && con[left] != -1){
            con[left] = -1;
            q.push(left);
            total++;
        }
        if(right != -1 && con[right] != -1){
            con[right] = -1;
            q.push(right);
            total++;
        }
      }
      return total==n ;
    }


    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
      vector<int> con(n,-1);
      vector<pair<int,int>> out(n);
      queue<int> q;
      int total = 0;

      for(int i = 0 ; i < n ; i ++){
        if(leftChild[i] != -1) {
          if(con[leftChild[i]] != -1) return false;
          con[leftChild[i]] = i;
          out[i].first == -1 ? out[i].first = leftChild[i] : out[i].second = leftChild[i];
        }
        if(rightChild[i] != -1) {
          if(con[rightChild[i]] != -1) return false;
          con[rightChild[i]] = i;
          out[i].first == -1 ? out[i].first = rightChild[i] : out[i].second = rightChild[i];
        }
      }

      for(int i = 0 ; i < con.size() ; i++){
        if(con[i]==-1) q.push(i);
        total++;
      }

      if(q.size() != 1) return false;
    
      while(!q.empty()){
        int node = q.front(); q.pop();
        //cout<<"node: "<<node<<endl;
        auto [left,right] = out[node] ;
          //cout<<"i: "<<i<<endl;
          if(con[left] != -1){
            con[left] = -1;
            q.push(left);
            total++;
          }
          if(con[right] != -1){
            con[right] = -1;
            q.push(right);
            total++;
          }
      }
        //cout<<"dsfdf"<<endl;
      // for(int i : con){
      //     //cout<<"i: "<<i<<endl;
      //   if(i != -1) return false;
      // }

      return total==n ;
    }
};