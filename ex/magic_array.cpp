#include <iostream>
#include <vector>

using namespace std;
vector<int> nums;
bool run = true; 

void show(vector<int> arr){
  for (int i = 0; i < arr.size(); i++){
    cout << arr[i] << " ";
  }

  cout << endl;
}

void process(int iPos, vector<int> arr){
  if (iPos >= nums.size() || !run){
    return; 
  }

  if(arr.size() > 1){
    int minn = arr[0];
    int maxx = arr[0];
    for (int i = 0; i < arr.size(); i++){
      if(minn > arr[i]){
        minn = arr[i];
      }else if(maxx < arr[i]){
        maxx = arr[i];
      }
    }

    int size = arr.size();
    if (maxx - minn >= size)
    {
      run = false; 
      return;
    }
  }

  arr.push_back(nums[iPos + 1]);
  process(iPos + 1, arr);
  process(iPos + 1, vector<int>{nums[iPos + 1]});
}

int main()
{
  int n;
  cin >> n;
  nums.resize(n);
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  };

  process(0, vector<int>{nums[0]});
  if(run){
    cout << "No" << endl;
  }else{
    cout << "Yes" << endl;
  }

  return 0;
}