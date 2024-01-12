#include "HouseRobberII.hpp"

// std::vector<int> Solution::sortByCash(std::vector<int>& nums){
//   std::vector<int> copy = nums;
//   for(int i = 1; i < copy.size(); ++i) {
//           int key = copy[i];
//           int j = i - 1;
//           while (j >= 0 && copy[j] > key) {
//               copy[j + 1] = copy[j];
//               j--;
//           }
//           copy[j + 1] = key;
//       }
//       return copy;
// }
bool comparator(const std::pair<int,std::pair<int,int>>& a,const std::pair<int,std::pair<int,int>>& b){
  return a.first < b.first;
}

int Solution::rob(std::vector<int>& nums){

int total = 0;
int currentTotal = 0;
std::vector<std::pair<int,std::pair<int,int>>> moneyNeighVect;
//std::vector<int> moneyVect = nums;

  if ( nums.size() <= 3){
      for (int money : nums){
        if ( money > total){
          total = money;
        }
      }
      
    }
  else{  

for (int i = 0 ; i<nums.size() ; i++){
  if ( i == 0 ){
    moneyNeighVect.push_back({nums[i], {nums.size()-1,1}});
  }else if ( i == nums.size()-1){
    moneyNeighVect.push_back({nums[i], {i-1,0}});
  }else{
    moneyNeighVect.push_back({nums[i], {i-1,i+1}});
  }
}

std::sort(moneyNeighVect.begin(),moneyNeighVect.end(),comparator);

for ( int firstIndex = moneyNeighVect.size()-1 ; firstIndex >= 0 ; firstIndex --){
int targetMoney = moneyNeighVect[firstIndex].first;
std::vector<int> neighboursWatchList;
neighboursWatchList.push_back(moneyNeighVect[firstIndex].second.first);
neighboursWatchList.push_back(moneyNeighVect[firstIndex].second.second);

  std::cout<<"first Index: " << firstIndex <<"\tSecond Index: ";
  for ( int secondIndex = moneyNeighVect.size()-1 ; secondIndex >= 0 ; secondIndex --){
    //for (int i : neighboursWatchList) std::cout<<i<<std::endl;
    
    if(secondIndex == firstIndex){
      //std::cout<<"Here comes the money: "<< secondIndex <<"::"<< firstIndex <<std::endl;
      continue;
    }
    std::cout<< secondIndex <<" ";

    int nextTargetHome = 0 ;
    int currentMoney = moneyNeighVect[secondIndex].first;
    std::pair<int,int> currentNeighbours = moneyNeighVect[secondIndex].second;
    if(currentNeighbours.first!=nums.size()-1 && currentNeighbours.second!=1){
      nextTargetHome = (currentNeighbours.first)+1;
    }

    // std::cout<<currentNeighbours.first<<std::endl;
    // std::cout<<currentNeighbours.second<<std::endl;
    // std::cout<<nextTargetHome<<std::endl;

    auto check = std::find(neighboursWatchList.begin(),neighboursWatchList.end(),nextTargetHome);
    // auto secondCheck = std::find(neighboursWatchList.begin(),neighboursWatchList.end(),currentNeighbours.second);
    
    if (check ==neighboursWatchList.end()&& check ==neighboursWatchList.end()){
    
      targetMoney += currentMoney; 
      neighboursWatchList.push_back(currentNeighbours.first);
      neighboursWatchList.push_back(currentNeighbours.second);
      //std::cout<<"Y"<<std::endl;
    }else{
      // std::cout<<"N"<<std::endl;
      continue;
    }
    
    // std::cout<<"-------"<<std::endl;
    if (targetMoney > total){
      total = targetMoney;
    }
  }
  
     std::cout<<""<<std::endl;
}
// for(auto i : moneyNeighMap){
//   std::cout<<i.first<<std::endl;
//   std::cout<<i.second.first<<": :"<<i.second.second<<std::endl;
// }
// for ( int i = 0 ; i < moneyVect.size() ; i ++){
//   int targetMoney = 0;
//   int index = moneyVect.size()-1-i;
//   std::pair<int,int> currentNeighbouts = moneyNeighMap.()moneyVect[i];
//   if (std::find())

// }
  }

  return total;
}


int main(){
  std::vector<int> test = {94,40,49,65,21,21,106,80,92,81,679,4,61,6,237,12,72,74,29,95,265,35,47,1,61,397,52,72,37,51,1,81,45,435,7,36,57,86,81,72};
  std::cout<< test.size() << std::endl;
  Solution s1;
  // std::vector<int> testVect = s1.sortByCash(test);
  // for (int i : testVect) std::cout << i << std::endl;
  //s1.largestSum(test);
 std::cout<< s1.rob(test) << std::endl;

return 0;
}

// ONLY WORKS IF 1st HOUSE IS THE MOST MONEY 

//std::vector<std::pair<int,std::pair<int,int>>> Solution::sortedMoneyNeighbourVector(std::vector<int>& nums){
// //std::vector<int> moneyVect = nums;
// std::vector<std::pair<int,std::pair<int,int>>> moneyNeighVect;


// for (int i = 0 ; i<nums.size() ; i++){
//   if ( i == 0 ){
//     moneyNeighVect.push_back({nums[i], {nums.size()-1,1}});
//   }else if ( i == nums.size()-1){
//     moneyNeighVect.push_back({nums[i], {i-1,0}});
//   }else{
//     moneyNeighVect.push_back({nums[i], {i-1,i+1}});
//   }
// }
// std::sort(moneyNeighVect.begin(),moneyNeighVect.end(),comparator);
// return moneyNeighVect;
// }

// int Solution::rob_max(std::vector<int>& nums,std::vector<std::pair<int,std::pair<int,int>>>& moneyNeighVect){
// int total = 0;
// std::vector<int> neighboursWatchList;
// int targetMoney = moneyNeighVect[moneyNeighVect.size()-1].first;
// neighboursWatchList.push_back(moneyNeighVect[moneyNeighVect.size()-1].second.first);
// neighboursWatchList.push_back(moneyNeighVect[moneyNeighVect.size()-1].second.second);

// for ( int i = moneyNeighVect.size()-2 ; i >= 0 ; i --){

//   int nextTargetHome = 0 ;

//   int currentMoney = moneyNeighVect[i].first;
//   std::pair<int,int> currentNeighbours = moneyNeighVect[i].second;
//   if(currentNeighbours.first!=nums.size()-1 && currentNeighbours.second!=1){
//     nextTargetHome = (currentNeighbours.first)+1;
//   }

//   auto check = std::find(neighboursWatchList.begin(),neighboursWatchList.end(),nextTargetHome);
  
//   if (check ==neighboursWatchList.end()&& check ==neighboursWatchList.end()){
   
//     targetMoney += currentMoney; 
//     neighboursWatchList.push_back(currentNeighbours.first);
//     neighboursWatchList.push_back(currentNeighbours.second);
//   }else{
//     continue;
//   }
// }

// total = targetMoney;


//   return total;
// }



// int Solution::rob_prototype(std::vector<int>& nums){
//  int total = 0;

//   if ( nums.size() <= 3){
//       for (int money : nums){
//         if ( money > total){
//           total = money;
//         }
//       }
      
//     }
//   else{  
//     int currNeighbourIndexR;
//     int  currNeighbourIndexL;

//     for ( int i = 0 ;i < nums.size() ; i++){
//       std::vector<int> remainingNums = nums;
      
//       int currentNum = nums[i];
//       int largestNum = 0;
//       if( i == 0){
//         // currNeighbourIndexR= 1;
//         // currNeighbourIndexL =nums.size()-1;
//         remainingNums.pop_back();
//         remainingNums.erase(remainingNums.begin()+1);
//         remainingNums.erase(remainingNums.begin());
        
//       }else if ( i == nums.size()-1){
//         // currNeighbourIndexR= 0;
//         // currNeighbourIndexL =i-1;
//         remainingNums.erase(remainingNums.begin()+i-1);
//         remainingNums.pop_back();
//         remainingNums.erase(remainingNums.begin());
//       }else{
//         // currNeighbourIndexR = i + 1;
//         // currNeighbourIndexL = i - 1;
//         std::vector<int> indeces = {i+1,i,i-1};
//         for (int i : indeces ) remainingNums.erase(remainingNums.begin()+i);
//       }
//       // std::cout<<currNeighbourIndexR<<": :"<<currNeighbourIndexL<<" total: ";
//       // std::cout<<total<<std::endl;
//       // remainingNums.erase(remainingNums.begin()+currNeighbourIndexR);
//       // remainingNums.erase(remainingNums.begin()+currNeighbourIndexL);
//       std::sort(remainingNums.begin(),remainingNums.end());
//       largestNum = remainingNums[remainingNums.size()-1];
//       int currTotal = currentNum + largestNum;

//       if( currTotal > total){
//         total = currTotal;
//       }
//   }
//   }
//   return total;
// }



// int Solution::rob_prototype(std::vector<int>& nums){
//  int total = 0;

//   if ( nums.size() <= 3){
//       for (int money : nums){
//         if ( money > total){
//           total = money;
//         }
//       }
      
//     }
//   else{  
//     int currNeighbourIndexR;
//     int  currNeighbourIndexL;

//     for ( int i = 0 ;i < nums.size() ; i++){
//       std::vector<int> remainingNums = nums;
      
//       int currentNum = nums[i];
//       int largestNum = 0;
//       if( i == 0){
//         // currNeighbourIndexR= 1;
//         // currNeighbourIndexL =nums.size()-1;
//         remainingNums.pop_back();
//         remainingNums.erase(remainingNums.begin()+1);
//         remainingNums.erase(remainingNums.begin());
        
//       }else if ( i == nums.size()-1){
//         // currNeighbourIndexR= 0;
//         // currNeighbourIndexL =i-1;
//         remainingNums.erase(remainingNums.begin()+i-1);
//         remainingNums.pop_back();
//         remainingNums.erase(remainingNums.begin());
//       }else{
//         // currNeighbourIndexR = i + 1;
//         // currNeighbourIndexL = i - 1;
//         std::vector<int> indeces = {i+1,i,i-1};
//         for (int i : indeces ) remainingNums.erase(remainingNums.begin()+i);
//       }
//       // std::cout<<currNeighbourIndexR<<": :"<<currNeighbourIndexL<<" total: ";
//       // std::cout<<total<<std::endl;
//       // remainingNums.erase(remainingNums.begin()+currNeighbourIndexR);
//       // remainingNums.erase(remainingNums.begin()+currNeighbourIndexL);
//       std::sort(remainingNums.begin(),remainingNums.end());
//       largestNum = remainingNums[remainingNums.size()-1];
//       int currTotal = currentNum + largestNum;

//       if( currTotal > total){
//         total = currTotal;
//       }
//   }
//   }
//   return total;
// }


 // for (int i = 1 ; i < nums.size() ; i++){
    //   if ( i = nums.size()-1){
    //   currNeighbourIndexL = i - 1;
    //   currNeighbourIndexR = 0;
    //   }else{
    //   currNeighbourIndexL = i - 1;
    //   currNeighbourIndexR = i + 1;
    //   }
    
      
    //       // if ( nums[i] > largestNum){
    //       //   secLargestNum = largestNum;
    //       //   largestNum = nums[i];
            
    //       // }else if(nums[i] > secLargestNum){
    //       //   secLargestNum = nums[i];
    //       // }
        
    //   }

      // int totalA = largestNumA + secLargestNumA;
      // int totalB = largestNumB + secLargestNumB;
      // total = std::max(totalA,totalB);  
      // std::cout<<"largest "<<largestNumA<<"\tsec largest "<<secLargestNumA<<std::endl;
      //  std::cout<<"largest "<<largestNumB<<"\tsec largest "<<secLargestNumB<<std::endl;

// int largestNumA = nums[0];
//     int secLargestNumA = 0;
//     int largestNumB= nums[1];
//     int secLargestNumB = 0;

//     for (int i = 2 ; i < nums.size() ; i++){
//         if (i % 2 == 0){
//           if ( nums[i] > largestNumA){
//             secLargestNumA = largestNumA;
//             largestNumA = nums[i];
            
//           }else if(nums[i] > secLargestNumA){
//             secLargestNumA = nums[i];
//           }
//         }else{
//           if ( nums[i] > largestNumB){
//             secLargestNumB = largestNumB;
//             largestNumB = nums[i];
            
//           }else if(nums[i] > secLargestNumB){
//             secLargestNumB = nums[i];
//           }
//         }
//       }
//       int totalA = largestNumA + secLargestNumA;
//       int totalB = largestNumB + secLargestNumB;
//       total = std::max(totalA,totalB);  
//       std::cout<<"largest "<<largestNumA<<"\tsec largest "<<secLargestNumA<<std::endl;
//        std::cout<<"largest "<<largestNumB<<"\tsec largest "<<secLargestNumB<<std::endl;

// int Solution::largestSum(std::vector<int>& nums){
//   int largestNum = nums[0];
//   int smallestNum = nums[0];
//   int largestTotal = 0;
//   for ( int i = 1 ; i < nums.size() ; i++){
//       if(nums[i]>largestNum){
//         largestNum = nums[i];
//       }else {
//         if (nums[i]< smallestNum){
//         smallestNum = nums[i];}
//       }
//   }

//   std::cout<<"smallest:"<<smallestNum<<"largest"<<largestNum;
//   return 0;
// }



// int maxMoney = 0;
//   if ( nums.size() <= 3){
//     for (int money : nums){
//       if ( money > maxMoney){
//         maxMoney = money;
//       }
//     }
//   }
//   else{
//       if (nums.size()%2 == 0){
//         for ( int i = 0 ; i < (nums.size()/2)+1 ; i ++){ 
      
//         }
//        }
// }

