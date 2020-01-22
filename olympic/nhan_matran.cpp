#include <iostream>
#include <vector>

using namespace std;
int rowi = 1, colj = 2, scompare = 10;
vector<vector<int>> a = {{1, 2}, {3, 4}};
vector<vector<int>> b = {{5, 6}, {7, 8}};
vector<vector<int>> k; 

void init(){
  for (int i = 0; i < a.size(); i++){
    k.push_back(vector<int>());
    for (int j = 0; j < a[i].size(); j++)
    {
      k[i].push_back(0);
    }
  }
}

int main(){
  init();
  for (int row = 0; row < k.size(); row ++){
    for (int col = 0; col < k[row].size(); col++){
      int total = 0;
      for (int i = 0; i < a[row].size(); i++){
        total += a[row][i] * b[i][col];
      }

      k[row][col] = total;
    }
  }
  
  cout << k[rowi - 1][colj - 1] % 10 << endl;
  return 0;
}