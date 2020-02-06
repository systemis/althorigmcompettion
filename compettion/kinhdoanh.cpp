#include <iostream>
#include <vector>

using namespace std; 

struct street{
  int root; 
  struct street *next;
};

typedef struct street ST;
int n = 10;
vector<vector<int>> wayments = {{1, 4}, {2, 3}, {1, 5}};

void show(vector<vector<int>> arr){
  for (int i = 0; i < arr.size(); i++){
    cout << arr[i][0] << " " << arr[i][1] << endl;
  }

  cout << endl
       << endl;
}

void process(vector<vector<int>> arr, int count){
  if(count == 1){
    show(arr);
    return;
  }

  for (int i = 1; i < n; i++){
    for (int j = 1; j < n; j++){
      if(i == j){
        continue;
      }

      arr.push_back(vector<int>{i, j});
      process(arr, count + 1);
      arr.pop_back();
    }
  }
}

int main(){
  process(wayments, 0);
  return 0;
}