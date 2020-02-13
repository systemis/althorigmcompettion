#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

vector<int> a = {5, 1, 6, 10, 20, 30, 90, 190};
vector<int> b = {1, 8, 6, 10, 20, 90, 190};
vector<bool> checkedA, checkedB;
int maxlength = 0; 

void show(vector<int> arr){
  for (int i = 0; i < arr.size(); i++){
    cout << arr[i] << " ";
  }
  cout << endl;
}

void process(vector<int> arr){
  int size = arr.size();
  maxlength = max(maxlength, size);
  for (int i = 0; i < a.size(); i++)
  {
    for (int j = 0; j < b.size(); j++){
      if(checkedB[j] || checkedA[i])
        continue;
      if (a[i] == b[j])
      {
        if(arr.size() == 0 || arr[arr.size() - 1] * 2 <= a[i]){
          checkedA[i] = true;
          checkedB[j] = true;
          arr.push_back(a[i]);
          process(arr);
          checkedA[i] = false;
          checkedB[j] = false;
          arr.pop_back();
        }
      }
    }
  }
}

int main(){
  for (int ai = 0; ai < a.size(); ai++){
    checkedA.push_back(false);
  }
  for (int ai = 0; ai < b.size(); ai++){
    checkedB.push_back(false);
  }

  process(vector<int>());
  cout << maxlength << endl;
  return 0;
}