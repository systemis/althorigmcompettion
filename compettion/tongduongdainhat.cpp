#include <iostream> 
#include <vector> 

using namespace std;

vector<int> nums = {-2, 1, -3, 2, 1, -3, 0};
vector<int> result;
int maxLength = 0;

int total(vector<int> arr){
  int value = 0;
  for (int i = 0; i < arr.size(); i++){
    value += arr[i];
  }

  return value; 
}

void continue_check(int iPos, vector<int> numsgetted)
{
  int tong = total(numsgetted);
  if (tong > 0 && numsgetted.size() > maxLength)
  {
    maxLength = numsgetted.size();
    result = numsgetted;
  }

  if(iPos >= nums.size())
    return;
  numsgetted.push_back(nums[iPos]);
  continue_check(iPos + 1, numsgetted);
}

int main(){
  for (int i = 0; i < nums.size(); i++){
    continue_check(i, vector<int>());
  }

  for (int k = 0; k < result.size(); k++){
    cout << result[k] << " ";
  }

  cout << endl;
  return 0;
}