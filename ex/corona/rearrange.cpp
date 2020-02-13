#include <iostream>
#include <vector>

using namespace std; 

vector<int> nums = {7, 6, 10};
bool run = true; 

int UCLN2so(int a, int b){
  if(a % b == 0){
    return b;
  }

  return UCLN2so(b, a % b);
};

int UCLN(vector<int> arr){
  int r = arr[0];
  for(int i =1; i < arr.size(); i++){
    r = UCLN2so(r, arr[i]);
  }

  return r; 
}

void process(vector<int> arr, int count){
  cout << UCLN(arr) << endl;
  if (UCLN(arr) > 1)
  {
    cout << count << endl;
    run = false; 
  }

  if(!run){
    return; 
  }

  for (int i = 0; i < arr.size(); i++){
    if(i == 0){
      arr[i] -= 1;
      arr[i + 1] += 1;
      process(arr, count + 1);
      arr[i] += 1;
      arr[i + 1] -= 1;
    }else if(i == arr.size() - 1){
      arr[i] -= 1;
      arr[i - 1] += 1;
      process(arr, count + 1);
      arr[i] += 1;
      arr[i - 1] -= 1; 
    }else{
      arr[i] -= 1;

      arr[i - 1] += 1;
      process(arr, count + 1);
      arr[i - 1] -= 1;

      arr[i + 1] += 1;
      process(arr, count + 1);
      arr[i + 1] -= 1; 
    }
  }
}

int main(){
  // cout << UCLN(nums) << endl;
  process(nums, 0);
  return 0;
}