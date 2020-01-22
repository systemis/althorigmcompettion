#include <iostream>
#include <vector>

using namespace std;

struct Position{
  int x, y;
};
typedef struct Position POSITION; 

int p = 4;
vector<POSITION> result;
vector<vector<int>> rectangles = {
  {1, 1, 1, 1}, 
  {1, 3, 2, 4}, 
  {3, 1, 4, 2}, 
  {2, 2, 4, 4,}, 
};

bool check(vector<POSITION> arr){
  for (int i = 0; i < arr.size(); i++){
    for (int j = 0; j < arr.size(); j++){
      if(i == j){
        continue;
      }

      if(arr[j].x == arr[i].x || arr[j].y == arr[i].y){
        return false;
      }
    }
  }

  return true;
}

void solve(int iPos, vector<POSITION> comp){
  POSITION position;
  if(result.size() > 0)
  {
    return;
  };

  if (iPos == 0)
  {
    position.x = 1;
    position.y = 1;
    comp.push_back(position);
    solve(iPos + 1, comp);
    return; 
  }

  if(comp.size() == p){
    if(check(comp) && result.size() == 0){
      result = comp;
    }

    return; 
  }

  int a = rectangles[iPos][0];
  int b = rectangles[iPos][1];
  int c = rectangles[iPos][2];
  int d = rectangles[iPos][3];

  for (int x = a; x <= c; x++){
    for (int y = b; y <= d; y++){
      position.x = x;
      position.y = y;
      comp.push_back(position);
      solve(iPos + 1, comp);
      comp.pop_back();
    }
  }
}

int main(){
  solve(0, vector<POSITION>());
  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i].x << " " << result[i].y << endl;
  }

  return 0;
}