#include<vector>
#include<iostream>
#include<functional>
#include<algorithm>
#include <numeric>

using namespace std;

class Solution {
public:

    int threeSumClosest(vector<int>& nums, int target) {
         int res = 0;
         //sort(nums.begin(),nums.end());
         vector<int> threeVal(3);
         for(int i = 0 ; i < nums.size() ; i++){
            if(i<3){
              threeVal[i]=nums[i];
              res += nums[i];
              continue;
            }
            int chosenSum = res;
            int chosenIndex = -1;
            for(int j = 0 ; j < threeVal.size() ; j++){
              int currentSum = res - threeVal[j] + nums[i];
              cout<<"currentSum: "<<currentSum<<"\t\tabs(target-currentSum): "<<abs(target-currentSum)<<endl;
              if(abs(target-currentSum)<= abs(target-chosenSum)){
                chosenIndex = j;
                chosenSum = currentSum;
              }
            }
            if(chosenIndex!=-1){
              threeVal[chosenIndex] = nums[i];
              res = chosenSum;
            }
            cout<<"sum: "<<accumulate(threeVal.begin(),threeVal.end(),0)<<endl;
         }
         return accumulate(threeVal.begin(),threeVal.end(),0);
    }

    // int threeSumClosest(vector<int>& nums, int target) {
    //   int noSort = findClosestThree(nums,target);
    //   cout<<"noSort: "<<noSort<<endl;
    //   sort(nums.begin(),nums.end());
    //   int asc = findClosestThree(nums,target);
    //   cout<<"asc: "<<asc<<endl;
    //   sort(nums.rbegin(),nums.rend());
    //   int des = findClosestThree(nums,target);
    //   cout<<"des: "<<des<<endl;

    //   return (min(noSort,min(asc,des)));
    // }

    // int findClosestThreeTest(vector<int>& nums,int count,int sum,int startIndex,int target){
    //   int res = 10000;
    //   //if(count==2) return sum+nums[startIndex];
    //   if(count==3) return sum;

    //   for(int i = startIndex ; i<nums.size(); i++){
    //       // res = min(res,abs(target-findClosestThree(nums,count+1,sum+nums[i],i+1,target)));
    //       int threeVal = findClosestThree(nums,count+1,sum+nums[i],i+1,target);
    //       cout<<"abs(target-res): "<<abs(target-res)<<"\tabs(target-threeVal): "<<abs(target-threeVal)<<endl;
    //       res = abs(target-threeVal) < abs(target-res) ? threeVal : res;
    //       //res = min(abs(target-res),abs(target-findClosestThree(nums,count+1,sum+nums[i],i+1,target)));
    //   }

    //   return res;
    // }

    // int threeSumClosestTest(vector<int>& nums, int target) {
    //      return findClosestThree(nums,0,0,0,target);
    // }

};

int main(){

  Solution s;
  vector<int> test = {321,413,82,812,-646,-858,729,609,-339,483,-323,-399,-82,-455,18,661,890,-328,-311,520,-865,-174,55,685,-636,462,-172,-696,-296,-832,766,-808,-763,853,482,411,703,655,-793,-121,-726,105,-966,-471,612,551,-257,836,-94,-213,511,317,-293,279,-571,242,-519,386,-670,-806,-612,-433,-481,794,712,378,-325,-564,477,169,601,971,-300,-431,-152,285,-899,978,-419,708,536,-816,-335,284,384,-922,-941,633,934,497,-351,62,392,-493,-44,-400,646,-912,-864,835,713,-12,322,-228,340,-42,-307,-580,-802,-914,-142,575,-684,-415,718,-579,759,579,732,-645,525,114,-880,-603,-699,-101,-738,-887,327,192,747,-614,393,97,-569,160,782,-69,235,-598,-116,928,-805,-76,-521,671,417,600,-442,236,831,637,-562,613,-705,-158,-237,-299,808,-734,364,919,251,-163,-343,899};
  cout<<s.threeSumClosest(test,2218)<<endl;
  return 0;
}