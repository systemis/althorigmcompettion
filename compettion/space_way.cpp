#include <iostream>
#include <vector> 

using namespace std;

// 2 3 4 3 1 
// 3 4 3 1 2 
// 

int m = 4, n = 5; 
vector<vector<int>> matrix =
    {{1, 2, 5, 2, 1},
     {4, 3, 1, 2, 3},
     {2, 3, 5, 3, 1},
     {3, 2, 1, 1, 5}};

int rightCount = 2, downCount = 1; 

void out(){
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl
        << endl;
}

void move(int x, int y){
  // Move type R:
  for (int k = 0; k < x; k++){
    for (int i = 0; i < matrix.size(); i++){
      // matrix[i][n - 1] = matrix[i][0];
      int tmp = matrix[i][0];
      for (int j = 0; j < n - 1; j++)
      {
        matrix[i][j] = matrix[i][j + 1];
      }

      matrix[i][n - 1] = tmp;
    }
  }

  // Move type D:
  for (int k = 0; k < y; k++){
    for (int j = 0; j < n; j++){
      int tmp = matrix[0][j];
      for (int i = 0; i < m - 1; i++)
      {
        matrix[i][j] = matrix[i + 1][j];
      }
      matrix[m - 1][j] = tmp;
    }
  }
}

int main(){
  move(rightCount, downCount);
  out();

  return 0;
}