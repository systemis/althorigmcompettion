#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

vector<int> nums; 
int length = 0, maxx = 0, minn = 1000;

void show(vector<int> arr){
  for(int i =0; i < arr.size(); i++){
    cout << arr[i] << " ";
  }

  cout << endl;
}

void process(vector<int> arr){
  for (int i = 0; i < arr.size(); i++)
  {
    for (int j = 0; j < arr.size(); j++){
      if(arr[j] > arr[i]) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
      }
    }
  }

  for(int i =0; i < arr.size(); i++){
    int j = i; 
    vector<int> get = {arr[i]}; 
    while(arr[j + 1] - arr[j] == 1 && j < arr.size() - 1){
      get.push_back(arr[j + 1]);
      j +=1; 
    }

    int size = get.size();
    length = max(length, size);
    if(size == 7){
    }
  }
}

// ipos: 0
void rechange(vector<int> arr, int iPos, int mixi){
  process(arr);
  for (int i = iPos + 1; i < arr.size(); i++)
  {
    if(arr[i] == 0){
      // for (int j = maxx * -1; j <=maxx; j++)
      for (int j = mixi; j <=maxx + 1; j++)
      {
        arr[i] = j;
        rechange(arr, i, mixi + 1);
      }

      break;
    }
  }
}

int main(){
  int n; 
  cin >> n;
  nums.resize(n);
  for(int i =0; i < n; i++){
    cin >> nums[i];
  }

  for (int i = 0; i < nums.size(); i++){
    if (minn > nums[i]){
      minn = nums[i];
    }else if(maxx < nums[i]){
      maxx = nums[i];
    }

    for (int j = i + 1; j < nums.size(); j++){
      if(nums[i] == nums[j] && nums[i] != 0){
        nums.erase(nums.begin() + j);
      }
    }
  }

  if(maxx == 0){
    maxx = nums.size(); 
  }

  rechange(nums, -1, minn - 1);
  cout << length << endl;
  return 0;
}