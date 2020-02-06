#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> matrix = {
    {7, 6, 8, 9}, 
    {1, 2, 3, 0}, 
    {2, 4, 5, 7}, 
    {3, 5, 6, 9}};

bool check_matrix_doixung(vector<vector<int>> arr){
  int top_count = 0, left_count = 0;
  for (int row = 1; row < arr.size(); row ++){
    for (int left = row - 1; left >= 0; left --){
      left_count += arr[row][left];
      cout << arr[row][left] << endl;
    }

    for (int top = row - 1; top >= 0; top--){
      top_count += arr[row][top];
    }
  }
  if(top_count == left_count){
    return true; 
  }

  top_count = 0;
  left_count = 0;

  for (int row = 1; row < arr.size(); row++){
    for (int right = arr[row].size() - row; right < arr.size(); right++){
      left_count += arr[row][right];
      cout << arr[row][right] << endl;
    }

    for (int top = row - 1; top >= 0; top--){
      top_count += arr[row][top];
    }
  }

  return (top_count == left_count);
}

int main(){
  check_matrix_doixung(matrix);
  return 0;
}