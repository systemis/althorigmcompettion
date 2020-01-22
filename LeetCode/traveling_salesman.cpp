#include <iostream> 
#include <vector>
#include <math.h>

using namespace std;

// vector<vector<int>> matrix = {
//     {0, 3, 2, 1},
//     {3, 0, 1, 2},
//     {2, 1, 0, 4}, 
//     {1, 2, 4, 0},
// };
vector<vector<int>> matrix = {
    {0, 5, 9, 20},
    {7, 0, 10, 12},
    {15, 8, 0, 21}, 
    {5, 10, 27, 0},
};

vector<bool> checked;
int mincost = pow(10, 9);
void process(int iPos, vector<int> costs){
  if (costs.size() == matrix.size() - 1)
  {
    int cost = 0;
    costs.push_back(matrix[iPos][0]);
    for (int i = 0; i < costs.size(); i++)
    {
      cost += costs[i];
    }
    if (mincost > cost)
    {
      mincost = cost;
    }

    return; 
  }

  for (int j = 0; j < matrix[iPos].size(); j++){
    if(iPos == j)
      continue;
    if(!checked[j]){
      checked[j] = true;
      costs.push_back(matrix[iPos][j]);
      process(j, costs);
      costs.pop_back();
      checked[j] = false;
    }
  }
}

int main(){
  for (int i = 0; i < matrix.size(); i++){
    checked.push_back(false);
  }

  checked[0] = true;
  process(0, vector<int>());
  cout << mincost << endl;
  return 0;
}