#include <iostream>
#include <vector>
#include <math.h>
#include <cstdlib>

using namespace std; 

vector<int> nums;
int k; 

void random_nums(int n){
  for (int i = 0; i < n; i++){
    nums[i] = rand() % 900;
  }
}

int main()
{
  int n; 
  cin >> n >> k;
  nums.resize(n);
  random_nums(n);
  // for (int i = 0; i < n; i++)
  // {
  //   cin >> nums[i];
  // }

  long length = 10000;
  for (int i = 0; i < n; i++)
  {
    int total = nums[i];
    if(total >= k){
      cout << "DS" << 1 << endl;
      return 0;
    }

    for (int j = i + 1; j < n; j++)
    {
      total += nums[j];
      if(total >= k && (j - i) < length){
        length = j - i + 1; 
      }
    }
  }

  if(length == 10000){
    cout << -1 << endl;
  }else{
    cout << length << endl;
  }

  return 0;
}