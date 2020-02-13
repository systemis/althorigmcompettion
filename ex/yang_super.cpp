#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int gcd(int a, int b)
{
  // if (b == 0)
    // return a;
  // return gcd(b, a % b);
  for (int i = 2; i <= max(a, b); i++){
    if(a % i == 0 && b %i == 0){
      return i;
    }
  }

  return 1; 
}

int main(){
  // cout << gcd(12, 8) << endl;
  // return 0;
  vector<int> nums;
  int n;
  cin >> n;
  nums.resize(n);
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }

  if (n == 1)
  {
    for (int i = 2; i <= nums[0]; i++)
    {
      if (nums[0] % i == 0)
      {
        cout << i << endl;
        return 0;
      }
    }

    cout << "LN" << endl;
    return 0;
  }

  int UC = nums[0];
  for (int i = 1; i < n; i++){
    UC = gcd(UC, nums[i]);
    cout << nums[i] << " " << UC << endl;
  }

  if(UC > 1){
    cout << UC << endl;
  }else{
    cout << "LN" << endl;
  }
}