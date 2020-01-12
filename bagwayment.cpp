#include <iostream>
#include <string>
#include <vector>

using namespace std;

int maxWeight = 25, maxValue = 0;
vector<int> weightInput = {15, 10, 90}; 
vector<int> valueInput = {2, 8, 9};
vector<int> posChecked, posMax; 

void create(int j){
  if(j == weightInput.size()){
    return; 
  }

  int values = valueInput[j];
  int weights = weightInput[j];
  posChecked.push_back(j);
  for (int i = j + 1; i < weightInput.size(); i++)
  {
    values += valueInput[i];
    weights += weightInput[i];
    posChecked.push_back(i);
    if (weights > maxWeight)
    {
      weights -= weightInput[i];
      values -= valueInput[i];
      posChecked.pop_back();
      continue;
    }else if(weights == maxWeight){
      if(maxValue < values){
        maxValue = values;
        posMax = posChecked;
        posChecked = {}; 
      }

      create(j + 1);
    }

    if(i == weightInput.size() - 1){
      if (maxValue < values)
      {
        maxValue = values;
        posMax = posChecked;
        posChecked = {};
      }

      create(j + 1);
    }
  }
}

int main()
{
  create(0);
  cout << maxValue << endl;
  return 0;
}