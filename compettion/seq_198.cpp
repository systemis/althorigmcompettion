#include <iostream>
#include <vector>
#include <math.h>
#include <cstdlib>

using namespace std;

vector<int> nums = {1, 3, 5, 7};
int result = pow(10, 2);

bool check_seq(vector<int> arr){
  for (int i = 0; i < arr.size(); i++){
    for (int j = 0; j < arr.size(); j++){
      if(i ==j)
        continue;
      int c = abs(arr[i] - arr[j]);
      if(c == 8 || c== 9|| c== 1){
        return false;
      }
    }
  }

  return true; 
}

void process(vector<int> arr, int count){
  if(arr.size() == 0){
    return; 
  }

  if(check_seq(arr)){
    result = min(count, result);
    return; 
  }

  for (int i = 0; i < arr.size(); i++){
    int tmp = arr[i];
    arr.erase(arr.begin() + i);
    process(arr, count + 1);
    arr.insert(arr.begin() + i, tmp); 
  };
}

int main()
{
  process(nums, 0);
  cout << result << endl;
  return 0;
}