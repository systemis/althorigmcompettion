#include <iostream>
#include <vector> 

using namespace std; 

int main(){
  int n;

  cout << "Nhap vao n: ";
  cin >> n;
  cout << endl; 

  int temp = 1;
  vector<vector<int>> matrix; 
  for (int i = 0; i <= n; i++)
  {
    vector<int> row;
    row.push_back(1);
    if (i == 0)
    {
      matrix.push_back(row);
      continue;
    }

    for (int j = 1; j <= i; j++){
      if(j == i){
        row.push_back(1);
        continue;
      }

      int total = matrix[i - 1][j - 1] + matrix[i - 1][j];
      row.push_back(total);
    }

    matrix.push_back(row);
  }

  for (int j = 0; j < matrix[matrix.size() - 1].size(); j++){
      cout << matrix[matrix.size() - 1][j] << " ";
  }
  cout << endl;

  return 0;
}