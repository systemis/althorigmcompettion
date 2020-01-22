#include <iostream>
#include <vector>

using namespace std;

vector<int> a = {1, 3, 10};
vector<int> b = {10, 15, 2};
vector<vector<int>> requests = {{1, 2}, {2, 3}, {1, 3}};

int main(){
  for (int r = 0; r < requests.size(); r++){
    int min = requests[r][0] - 1;
    int max = requests[r][1] - 1;

    int chuan1 = -1, chuan2 = -1;
    for (int i = 1; i <= 1000; i++){
      for (int j = min; j <= max; j++){
        if(chuan2 != 0){
          if(a[j] % i == b[j] % i){
            chuan2 = i;
          }else{
            chuan2 = 0; 
          }
        }
      }

      if(chuan2 != 0){
        chuan1 = chuan2;
      }

      chuan2 = -1;
    }

    cout << chuan1 << endl;
  }

  return 0;
}