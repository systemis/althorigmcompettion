#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

vector<int> nums;
long maxx = 0;
long tich(vector<int> arr)
{
  long r = 1;
  for (int i = 0; i < arr.size(); i++)
  {
    r = r * arr[i];
  }

  return r; 
}

void process(vector<int> arr, int iPos){
  if(iPos >= arr.size()){
    return; 
  }

  arr[iPos] -= 1;
  long tich_arr = tich(arr);
  if (maxx < tich_arr)
  {
    maxx = tich_arr;
  }

  arr[iPos] += 1;
  process(arr, iPos + 1);
}

int main(){
  int n;
  cin >> n;
  nums.resize(n);
  for (int i = 0; i < n;i++){
    cin >> nums[i];
  }

  process(nums, 0);
  maxx = maxx % 170901;
  cout << maxx << endl;
  return 0;
}