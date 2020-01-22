#include <iostream> 
#include <vector>

using namespace std;

vector<int> values = {1, 1, 2};
vector<bool> checked = {};
vector<vector<int>> result;

bool checkcomp(vector<int> arr){
  for (int i = 0; i < result.size(); i++){
    int check = true; 
    for (int j = 0; j < result[i].size(); j++)
    {
      if(result[i][j] != arr[j]){
        check = false;
      }
    }

    if(check){
      return check;
    }
  }

  return false;
}

void permuate(vector<int> arr){
  if(arr.size() == values.size()){
    if (!checkcomp(arr)){
      result.push_back(arr);
    }
    return;
  }

  for (int i = 0; i < values.size(); i++){
    if(!checked[i]){
      checked[i] = true;
      arr.push_back(values[i]);
      permuate(arr);

      arr.pop_back();
      checked[i] = false;
    }
  }
}

int main(){
  for (int i = 0; i < values.size(); i++){
    checked.push_back(false);
  }

  permuate(vector<int>());
  for (int i = 0; i < result.size(); i++)
  {
    for (int j = 0; j < result[i].size(); j++){
      cout << result[i][j] << " ";
    }

    cout << endl;
  }

  return 0;
}