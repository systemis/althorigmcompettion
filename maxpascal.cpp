#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> matrix = {
  {7}, 
  {2, 8}, 
  {5, 9, 3}, 
  {4, 6, 9, 2}, 
  {7, 8, 5, 6, 6}, 
  {1, 3, 4, 9, 8, 1}};

int maxL = 0;

void trying(int row, int col, int total){
  if(row == matrix.size() - 1){
    total += matrix[row][col];
    if (maxL < total)
    {
      maxL = total;
    }

    return;
  }

  if(row == 0){
    total = matrix[0][0];
    trying(row + 1, col, total);
    trying(row + 1, col + 1, total);
    return;
  }else{
    total += matrix[row][col];
    trying(row + 1, col + 1, total);
    trying(row + 1, col, total);
    return;
  }
}

int main(){
  trying(0, 0, 0);
  cout << "Tong: " << maxL << endl;
  return 0;
}