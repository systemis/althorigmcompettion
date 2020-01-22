#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> matrix = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9},
};

int main(){
  int N = matrix.size();
  for (int i = 0; i < N; i++){
    for (int j = i; j < N; j++){
      int tmp = matrix[i][j];
      matrix[i][j] = matrix[j][i];
      matrix[j][i] = tmp;

    }
  }

  for (int i = 0; i < N; i++){
    for (int j = 0; j < (N / 2); j++){
      int tmp = matrix[i][j];
      matrix[i][j] = matrix[i][N - 1 - j];
      matrix[i][N - 1 - j] = tmp;
    }
  }

  for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
      cout << matrix[i][j] << " ";
    }

    cout << endl;
  }
  return 0;
}