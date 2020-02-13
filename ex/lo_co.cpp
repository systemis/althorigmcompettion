#include <iostream>
#include <vector>

using namespace std; 

// vector<vector<int>> matrix;
// vector<bool> checked = {true, true, false};
int n, m, result = 0; 
int total(vector<int> arr)
{
  int r = arr[0];
  for (int i = 1; i < arr.size(); i++){
    r += arr[i];
  }

  return r; 
}

void process(vector<int> arr){
  if(arr.size() > 0 && total(arr) == n){
    result += 1;
    return; 
  }
  
  if(arr.size() > 0 && total(arr) > n){
    return;
  }

  for (int i = 1; i <= 3; i++){
    arr.push_back(i);
    process(arr);
    arr.pop_back();
  }
}

int main(){
  cin >> n >> m;
  process(vector<int>());
  cout << result % m << endl;
  return 0;
}

