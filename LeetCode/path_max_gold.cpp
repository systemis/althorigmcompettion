#include <iostream> 
#include <vector>

using namespace std;

vector<vector<bool>> checked; 
vector<vector<int>> grid = {
    {0, 6, 0}, {5, 8, 7}, {0, 9, 0}};

void init_checked(){
  for (int i = 0; i < grid.size(); i++){
    checked.push_back(vector<bool>());
    for (int j = 0; j < grid[i].size(); j++)
    {
      checked[i].push_back(false);
    }
  }
}

void progress(){

}

int main(){
  init_checked();

  return 0;
}