#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> request = {{1, 3}, {1, 5}};
vector<vector<int>> matrix = 
     {{1, 2, 1}, 
      {2, 3, 1}, 
      {1, 3, 4}, 
      {3, 4, 5}, 
      {4, 5, 6}, 
      {5, 1, 7}};

vector<vector<int>> result; 

void handling(int a, int b, int iPos, int count, int times, int qPos){
  for (int i = iPos; i < matrix.size(); i++){
    if(matrix[i][0] == a){
      if (matrix[i][1] == b){
        times += matrix[i][2];
        if (times < result[qPos][1]){
          result[qPos][1] = times;
        }else if(count < result[qPos][0]){
          result[qPos][0] = count;
        }

        return;
      }

      count += 1;
      times += matrix[i][2];
      handling(matrix[i][1], b, iPos + 1, count, times, qPos);
    }

    handling(a, b, i + 1, count, times, qPos);
  }
}

int main()
{
  for (int pj = 0; pj < request.size(); pj++){
    result.push_back(vector<int>({10*9, 10*9}));
    int a = request[pj][0];
    int b = request[pj][1];
    handling(a, b, 0, 0, 0, pj);
  }

  for (int k = 0; k < result.size(); k++){
    cout << result[k][0] << " " << result[k][1] << " " << endl;
  }
  return 0;
}