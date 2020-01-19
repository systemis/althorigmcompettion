#include <iostream> 
#include <vector>
#include <queue> 

using namespace std;

struct Position
{
  int row, col;
};
typedef struct Position POSITION;

vector<vector<int>> checkmap; 
vector<vector<int>> matrix =
    {{1, 1, 1, 1, 1, 1, 1, 1},
     {1, 0, 1, 0, 0, 0, 1, 1},
     {1, 0, 0, 0, 1, 1, 0, 0},
     {1, 1, 1, 0, 0, 0, 0, 1},
     {1, 1, 1, 0, 1, 1, 1, 1}};

void checking(POSITION frontPos){
  queue<POSITION> standing;
  standing.push(frontPos);
  int count = 0;
  
  while(!standing.empty()){
    POSITION pos = standing.front();
    standing.pop();
    for (int i = pos.row - 1; i <= pos.row + 1; i++){
      for (int j = pos.col - 1; j <= pos.col + 1; j++){
        if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[i].size())
          continue;
        if(matrix[i][j] == 0 && checkmap[i][j] == 0){
          POSITION posnew;
          posnew.row = i;
          posnew.col = j;
          checkmap[i][j] = 1;
          standing.push(posnew);
          count += 1;
          cout << matrix[i][j] << " ";
        }
      }
    }
  }
}

int main()
{
  for (int row = 0; row < matrix.size(); row++){
    checkmap.push_back(vector<int>());
    for (int col = 0; col < matrix[row].size(); col++){
      checkmap[row].push_back(0);
    }
  }
  
  for (int i = 0; i < matrix.size(); i++){
    for (int j = 0; j < matrix[i].size(); j++){
      if (matrix[i][j] == 0){
        POSITION pos;
        pos.row = i;
        pos.col = j;
        checking(pos);
      }
    }
  }

  return 0;
}