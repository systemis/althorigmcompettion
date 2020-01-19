#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<int> nums = {3, 2, 1};
int cost = 0; 

// 7,4,9,2 0 
// 7,6,9 6
// 13,
vector<int> min_minn(){
  int min1 = pow(10, 4), min2 = pow(10, 4);
  int iPos = 0, jPos = 0;
  for (int i = 0; i < nums.size(); i++){
    if(nums[i] < min1){
      min1 = nums[i];
      iPos = i;
    }
  }

  for (int j = nums.size() - 1; j >= 0; j--){
    if(nums[j] > min1 && nums[j] < min2){
      min2 = nums[j];
      jPos = j;
    }
  }

  return vector<int>{iPos, jPos};
}

vector<int> randomarr(){
  vector<int> arr; 
  for (int i = 0; i < 10000; i++)
  {
    arr.push_back(i + 1);
  }

  return arr;
}

void kinmas(){
  vector<int> toDEL = min_minn();
  int a = nums[toDEL[0]];
  int b = nums[toDEL[1]];
  nums.erase(nums.begin() + max(toDEL[0], toDEL[1]));
  nums.erase(nums.begin() + min(toDEL[0], toDEL[1]));

  cost += a + b;
  if(nums.size() > 0){
    nums.push_back(a + b);
    kinmas();
  }else{
    return; 
  }
}


int main(){
  kinmas();
  cout << cost << endl;
  return 0;
}