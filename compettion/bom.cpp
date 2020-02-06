#include <iostream>
#include <vector> 

using namespace std;

int m = 7;
vector<int> weights = {4, 6, 2};
vector<bool> checked;
vector<int> result;

int total(vector<int> arr){
  int c = 0;
  for (int i = 0; i < arr.size(); i++){
    c += arr[i];
  }

  return c;
}

void process(vector<int> getted){
  if(total(getted) <= m){
    if(getted.size() > result.size()){
      result = getted;
    }
  }else{
    return; 
  }

  for (int i = 0; i < weights.size(); i++){
    if(checked[i])
      continue;
    checked[i] = true;
    getted.push_back(weights[i]);
    process(getted);
    getted.pop_back();
    checked[i] = false;
  }
}

int main(){
  for (int i = 0; i < weights.size(); i++){
    checked.push_back(false);
  }

  process(vector<int>());
  for (int i = 0; i < result.size(); i++){
    cout << result[i] << " ";
  }
  cout << endl;
  return 0;
}