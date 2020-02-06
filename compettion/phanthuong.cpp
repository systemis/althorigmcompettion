#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<int> nums = {1, 3, 10, 2, 1, 4};
int result = 0, k = 2; 

void process(vector<int> arr, int count, int hieu){
  if (arr.size() < k || count == k)
  {
    result = max(result, hieu);
    return;
  }

  int f1 = arr[0], f2 = arr[1];
  hieu += abs(f1 - f2);
  arr.erase(arr.begin());
  arr.erase(arr.begin());
  process(arr, count + 1, hieu);
  hieu -= abs(f1 - f2);
  arr.insert(arr.begin(), f2);
  arr.insert(arr.begin(), f1);

  int l1 = arr[arr.size() - 1], l2 = arr[arr.size() - 2];
  hieu += abs(l1 - l2);
  arr.erase(arr.begin() + arr.size() - 1);
  arr.erase(arr.begin() + arr.size() - 1);
  process(arr, count + 1, hieu);
  hieu -= abs(l1 - l2);
  arr.push_back(l1);
  arr.push_back(l2);

  int tmp1 = arr[0], tmp2 = arr[arr.size() - 1];
  hieu += abs(tmp1 - tmp2);
  arr.erase(arr.begin());
  arr.erase(arr.begin() + arr.size() - 1);
  process(arr, count + 1, hieu);
  hieu -= abs(tmp1 - tmp2);
  arr.insert(arr.begin(), tmp1);
  arr.insert(arr.begin() + arr.size() - 1, tmp2);

  int front = arr[0];
  arr.erase(arr.begin());
  process(arr, count, hieu);
  arr.insert(arr.begin(), front);

  int last = arr[arr.size() - 1];
  arr.erase(arr.begin() + arr.size() - 1);
  process(arr, count, hieu);
  arr.insert(arr.begin() + arr.size() - 1, last);
}

int main(){
  process(nums, 0, 0);
  cout << result << endl;
  return 0;
}