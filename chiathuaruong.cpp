#include <iostream>
#include <vector>

using namespace std;

vector<int> nums = {100, 200, 250, 50, 300, 50, 50, 50};
vector<char> names = {'A', 'B', 'C'};
int result = 0; 

void checking_balance(vector<char> arr){
  int a = 0, b = 0, c = 0;
  for (int i = 0; i < arr.size();  i++){
    switch(arr[i]){
      case 'A':
        a += nums[i];
        break;
      case 'B':
        b += nums[i];
        break;
      case 'C':
        c += nums[i];
        break;
    }
  }

  if (a == b && a == c)
  {
    cout << a << " " << b << " " << c << endl;
    result++;
  }
}

void progress(vector<char> arr){
  if(arr.size() == nums.size()){
    checking_balance(arr);
    return;
  }

  for (int i = 0; i < names.size(); i++){
    arr.push_back(names[i]);
    progress(arr);
    arr.pop_back();
  }
}

int main(){
  progress(vector<char>());
  cout << result << endl;
  return 0;
}