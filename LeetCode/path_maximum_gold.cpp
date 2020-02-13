#include <iostream>
#include <vector> 
#include <cstdlib>

using namespace std;

struct POSITION{
  int row, col;
};

typedef struct POSITION position;

vector<vector<bool>> checked;
vector<vector<int>> matrix = {};


int maximunresult = 0;

int total(vector<int> arr){
  int r = arr[0];
  for (int i = 1; i < arr.size(); i++){
    r += arr[i];
  }

  return r; 
}

void process(position pos, vector<int> points){
  bool possible = false; 
  int row = pos.row, col = pos.col;
  for (int i = row - 1; i <= row + 1; i++)
  {
    if(i < 0 || i >= matrix.size())
      continue;

    for (int j = col - 1; j <= col + 1; j++)
    {
      if (j < 0 || j >= matrix[i].size())
        continue;
      if((i == row - 1 && j == col - 1) || (i == row - 1 && j == col + 1))
        continue;
      if ((i == row + 1 && j == col - 1) || (i == row + 1 && j == col + 1))
        continue;
      if (checked[i][j])
        continue;
      if(matrix[i][j] == 0){
        continue;
      }
      possible = true; 
      checked[i][j] = true;
      pos.row = i;
      pos.col = j;
      points.push_back(matrix[i][j]);
      process(pos, points);
      points.pop_back();
      checked[i][j] = false;
    }
  }

  if(!possible){
    int r = total(points);
    if (maximunresult < r)
    {
      maximunresult = r;
    }
    
    return;
  }
}

void fresh(){
  for (int i = 0; i < checked.size(); i++){
    for (int j = 0; j < checked[i].size(); j++){
      checked[i][j] = false; 
    }
  }
}


void random(int n){
  matrix.resize(n);
  for (int i = 0; i < n; i++)
  {
    matrix[i].resize(n);
    for (int j = 0; j < n; j++){
      matrix[i][j] = rand() % 1000;
    }
  }
}

int main(){
  int n; 
  cin >> n;
  random(n);
  checked.resize(matrix.size());
  for (int i = 0; i < matrix.size(); i++){
    checked[i].resize(matrix[i].size());
    for (int j = 0; j < matrix[j].size(); j++)
    {
      checked[i][j] = false; 
    }
  }


  for (int i = 0; i < matrix.size(); i++){
    for (int j = 0; j < matrix[i].size(); j++){
      if(i == 0 || i == matrix.size() - 1 || j == 0 || j == matrix[i].size() - 1){
        checked[i][j] = true;
        position POS;
        POS.row = i;
        POS.col = j;
        process(POS, vector<int>{matrix[i][j]});
        fresh();
      }
    }
  }

  cout << maximunresult << endl;
  return 0;
}