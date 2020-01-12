#include <iostream>
#include <vector> 

using namespace std;

vector<int> w_values = {5, 4, 4, 3};
vector<vector<int>> p_values = {{0, 2, 2, 2}, {2, 0, 3, 3}, {2, 3, 0, 4}, {2, 3, 4, 0}};
int mincos = 10*5; 

int cosinw_way(){
  int cos = 0;
  for (int i = 0; i < w_values.size(); i++){
    cos += w_values[i];
  }

  return cos;
}

int cosinp_way(){
  int cost = 0; 
  for (int i = 0; i < p_values.size(); i++)
  {
    for (int j = i; j < p_values[i].size(); j++){
      cost += p_values[i][j + 1];
      i++;
    }
  }

  return cost; 
}

int main(){
  mincos = min(cosinw_way(), mincos);
  mincos = min(cosinp_way(), mincos);

  cout << mincos << endl;
  return 0;
}