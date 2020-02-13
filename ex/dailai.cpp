#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> nums = {{20, 2}, {30, 1}, {25, 1}, {35, 1}, {60, 2}, {65, 2}, {10, 1}};
int a = 2, b = 2; 
int k = 1e9;

int main()
{
  // sort
  for (int i = 0; i < nums.size(); i++){
    for (int j = 0; j < nums.size(); j++){
      if(nums[j][0] > nums[i][0]){
        vector<int> tmp = nums[j];
        nums[j] = nums[i];
        nums[i] = tmp; 
      }
    }
  }

  for (int i = nums.size() - 1; i >= 0; i--){
    int caytung = 0;
    int caytruc = 0; 
    for (int j = i; j >=0; j--)
    {
      if(nums[j][1] == 2){
        caytruc++; 
      }else{
        caytung++; 
      }

      if (caytung == a && caytruc == b)
      {
        k = min(nums[i][0] - nums[j][0], k);
      }
    }
  }

  cout << k << endl;
}
