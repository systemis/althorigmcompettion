#include <iostream>
#include <vector>

using namespace std;
struct robot
{
  int row, col;
  int xspeed, yspeed;
};
typedef struct robot ROBOT;
ROBOT r; 
vector<vector<char>>
    matrix = {
        {'#', '#', '#'},
        {'#', '.', '.'},
        {'#', '.', '.'},
        };
// vector<vector<char>>
//     matrix = {
//         {'#', '#', '#'},
//         {'#', '.', '.'},
//         {'#', '.', '.'},
//         };

int xStart = 2, yStart = 5;
int S = 7;


int main(){
  r.row = yStart - 1;
  r.col = xStart - 1;
  r.xspeed = 0;
  r.yspeed = -1;
  int nrow = r.row + r.yspeed;
  int ncol = r.col + r.xspeed;

  for (int i = 0; i < S; i++)
  {
    if(r.row >= matrix.size() || r.row <= 0){
      r.row += r.yspeed;
      r.col += r.xspeed;
      continue;
    }

    int nrow = r.row + r.yspeed;
    int ncol = r.col + r.xspeed;
    while (nrow < matrix.size() && matrix[nrow][ncol] == '#')
    {
      if (r.yspeed == -1 && r.xspeed == 0)
      {
        r.yspeed = 0;
        r.xspeed = -1;
        nrow = r.row + r.yspeed;
        ncol = r.col + r.xspeed;
        continue;
      }else if (r.xspeed == -1 && r.yspeed == 0){
        r.xspeed = 0;
        r.yspeed = 1;
        nrow = r.row + r.yspeed;
        ncol = r.col + r.xspeed;
        continue;
      }else if(r.xspeed == 0 && r.yspeed ==1){
        r.xspeed = 1;
        r.yspeed = 0;
        nrow = r.row + r.yspeed;
        ncol = r.col + r.xspeed;
        continue;
      }else if(r.xspeed == 1 && r.yspeed == 0){
        r.yspeed = -1;
        r.xspeed = 0;
        nrow = r.row + r.yspeed;
        ncol = r.col + r.xspeed;
        continue;
      }
    }

    r.row = nrow;
    r.col = ncol;
    
  }

  cout << r.row << " " << r.col << endl;
  return 0;
}