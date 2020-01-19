#include <iostream>
#include <vector>

using namespace std;

vector<bool> checked;
vector<vector<int>> values = {
    {0, 2},
    {3, 4},
    {4, 5},
    {5, 17},
    
    {1, 2},
    {2, 5},
    
    {2, 16},
    
    {3, 21},
};

void sort(){
  for (int i = 0; i < values.size(); i++){
    for (int j = 0; j < values.size(); j++){
      if(values[j][0] > values[i][0]){
        vector<int> tmp = values[i];
        values[i] = values[j];
        values[j] = tmp;
      }
    }
  }
}

int main(){
  sort();
  for (int i = 0; i < values.size(); i++){
    checked.push_back(false);
    cout << values[i][0] << " " << values[i][1] << endl;
  }

  vector<int> result;
  for (int i = 0; i < values.size(); i++)
  {
    int end = values[i][1];
    for (int j = 0; j < values.size(); j++){
      if(checked[j])
        continue;
      if (end <= values[j][0])
      {
        checked[j] = true;
        end = values[j][1];
      }
    }
  }
  for (int i = 0; i < values.size(); i++)
  {
    cout << checked[i] << " ";
  }
  cout << endl;

  return 0;
}