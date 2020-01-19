#include <iostream>
#include <vector>

using namespace std;

int c = 0;
vector<vector<int>> test = 
  {{1, 3}};

int total(vector<int> arr){
  int tong = 0;
  for (int i = 0; i < arr.size(); i++){
    tong += arr[i];
  }

  return tong; 
}
void maxway(int k, int n, vector<int> checked){
  if(total(checked) == n){
    c += 1; 
    return;
  }else if(total(checked) > n){
    return;
  }

  for (int i = 1; i <= k;i++){
    checked.push_back(i);
    maxway(k, n, checked);
    checked.pop_back();
  }
}

int main(){
  for (int i = 0; i < test.size(); i++){
    maxway(test[i][0], test[i][1], vector<int>());
  }

  cout << c << endl;
  return 0;
}