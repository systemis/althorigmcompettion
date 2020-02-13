#include <iostream>
#include <vector> 

using namespace std;


int main(){
  vector<int> nums; 
  int n, k, way =0;
  cin >> n >> k;
  nums.resize(n);
  for (int i = 0; i < n; i++){
    cin >> nums[i];
  }

  for (int i = 0; i <= nums.size() - 3; i++)
  {
    int total = 0;
    for (int j = i; j < i + 3; j++)
    {
      total += nums[j];
    }

    if (total >= k)
    {
      way += 1;
    }
  }
  
  cout << way << endl;
  return 0;
}