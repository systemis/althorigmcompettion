#include <iostream>
#include <vector>
#include <math.h>

using namespace std; 

struct POSITION{
  int row, col;
};

typedef struct POSITION position; 
int m = 5, n = 3, minximunCount;
vector<vector<int>> matrix = {
  {1, 1, 10}, 
  {10, 1, 100}, 
  {1, 1, 1000}, 
  {1, 10, 100}, 
  {1, 1, 1}};
vector<vector<bool>> checked; 
  

int total(vector<int> arr){
  int r = 1;
  for (int i = 0; i < arr.size(); i++){
    r = r * arr[i];
  }
  return r; 
}

void process(POSITION position, vector<int> arr){
  if (position.row == m - 1 && position.col == n - 1)
  {
    int c = total(arr);
    cout << c << endl;
    int count = 0;
    while(c % 10 ==0){
      c = c / 10;
      count++; 
    }

    minximunCount = min(count, minximunCount);
    return;
  }

  int row = position.row, col = position.col;
  for (int i = row - 1; i <= row + 1; i++){
    if(i < 0 || i >= m)
      continue;
    for (int j = col - 1; j <= col + 1; j++){
      if(j < 0 || j >= n)
        continue;
      if((i == row - 1 && j == col - 1) || 
         (i == row - 1 && j == col + 1) ||
         (i == row + 1 && j == col - 1) ||
         (i == row + 1 && j == col + 1)){
        continue;
      }
      if (checked[i][j])
        continue;

      checked[i][j] = true;
      position.row = i;
      position.col = j;
      arr.push_back(matrix[i][j]);
      process(position, arr);
      arr.pop_back();
      checked[i][j] = false;
    }
  }
}

int main()
{
  for (int i = 0; i < m; i++){
    checked.push_back(vector<bool>());
    for (int j = 0; j < n; j++){
      checked[i].push_back(false);
    }
  }

  POSITION pos;
  pos.row = 0;
  pos.col = 0;

  checked[0][0] = true;
  process(pos, vector<int>{matrix[0][0]});
  cout << minximunCount << endl;

  return 0;
}