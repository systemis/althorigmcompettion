#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

vector<int> nums = { 1, 2, 3, 4, 5, 6};
vector<bool> checked;
vector<vector<int>> geted; 
int result = 0;

int findIndex(vector<int> arr){
  for (int i = 0; i < geted.size(); i++){
    vector<int> c = geted[i];
    if(c.size() != arr.size()){
      continue;
    }

    int count = 0;
    for (int j = 0; j < c.size(); j++)
    {
      if(c[j] == arr[j])
        count++;
    }

    if(count == c.size()){
      return i; 
    }
  }

  return -1; 
}

bool isATH(vector<int> arr){
  if(arr.size() < 3){
    return false;
  }

  int distance = abs(arr[0] - arr[1]);
  for (int i = 1; i < arr.size() - 1; i++){
    if(abs(arr[i] - arr[i + 1]) != distance){
      return false;
    }
  }

  int total = 1;
  for (int i = 0; i < arr.size(); i++){
    total *= arr[i];
  }

    return true;
}

void out(vector<int> arr){
  for (int i = 0; i < arr.size(); i++){
    cout << arr[i] << " ";
  }
  cout << endl;
}

void init_checked(){
  for (int i = 0; i < nums.size(); i++){
    checked.push_back(false);
  }
}


void process(vector<int> arr){
  if(isATH(arr)){
    sort(arr.begin(), arr.end());
    if(findIndex(arr) == -1){
      geted.push_back(arr);
      result += 1; 
      out(arr);
    }
  }

  for (int i = 0; i < nums.size(); i++){
    if(!checked[i]){
      checked[i] = true;
      arr.push_back(nums[i]);
      process(arr);
      arr.pop_back();
      checked[i] = false;
    }
  }
}

int main(){
  init_checked();
  process(vector<int>());
  cout << result << endl;
  return 0;
}