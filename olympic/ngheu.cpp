#include <iostream>
#include <vector>

using namespace std;

struct Cursor{
  int col, row;
};

typedef struct Cursor CURSOR;
CURSOR position;
vector<vector<int>>
    matrix = {
        {1, 2, 3, 1},
        {2, 3, 1, 2},
        {3, 1, 2, 3},
};

vector<vector<int>> car_c = {
  {10, 1, 2, 2, 2}, 
  {10, 1, 2, 4, 2}};

vector<int> redlines = {2, 1};
vector<int> result; 
int mtype = 1; 

void process(int iPos, int jPos){
  if (jPos >= car_c[iPos].size() ||
      position.row >= matrix.size() ||
      position.col >= matrix[position.row].size())
  {
    return;
  }
  
  int redLine = redlines[iPos];
  int carC = car_c[iPos][jPos];
  int row = position.row;
  int col = position.col; 

  // compare dieu kien
  if(matrix[row][col] > redLine){
    int lss = matrix[row][col] - redLine;
    if(lss <= carC){
      matrix[row][col] = redLine;
      result[iPos] += lss;
    }
  }
  
  if(col == matrix[row].size() - 1 && mtype == 1){
    row += 1;
    mtype = -1;
  }else if(col == 0 && mtype == -1){
    row += 1;
    mtype = 1;
  }else{
    col += mtype;
  }

  position.row = row;
  position.col = col;

  process(iPos, jPos + 1);
}

int main()
{
  position.row = 0;
  position.col = 0;
  for (int i = 0; i < redlines.size(); i++){
    result.push_back(0);
    position.row = 0;
    position.col = 0;
    mtype = 1; 
    process(i, 0);
  }

  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i] << endl;
  }

  return 0; 
}