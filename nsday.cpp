#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std;

vector<int> values = {-1, 2, -2, -3, 5};
int maxL = 0; 

int freturn(int i, int j, int k){
  return values[i] + 2 * values[j] + 3 * values[k];
}

int main()
{
  for (int i = 0; i < values.size(); i++){
    for (int j = i + 1; j < values.size(); j++){
      for (int k = j + 1; k < values.size(); k++){
        maxL = max(maxL, freturn(i, j, k));
      }
    }
  }

  cout << maxL << endl;
  return 0;
}