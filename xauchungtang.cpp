#include <iostream>
#include <vector> 

using namespace std;

vector<int> a_arr = {5, 6, 10, 20, 8, 9, 2, 11, 9};
vector<int> b_arr = {1, 8, 6, 10, 20, 8};

void find(vector<int> xauchung, int iPos, int jPos){
  if (jPos == 0)
  {
    for (int j = 0; j < b_arr.size(); j++){
      if (b_arr[j] == xauchung[xauchung.size() - 1]){
        xauchung.push_back(a_arr[iPos + 1]);
        find(xauchung, iPos + 1, j + 1);
        return;
      }
    }
  }else{
    if (a_arr[iPos] == b_arr[jPos]){
      if (jPos == b_arr.size() - 1 || iPos == a_arr.size() - 1){
        return;
      }

      xauchung.push_back(a_arr[iPos + 1]);
      for (int k = 0; k < xauchung.size(); k++){
        cout << xauchung[k] << " ";
      }
      cout << endl;
      find(xauchung, iPos + 1, jPos + 1);
    }
  }
}

int main()
{
  for (int i = 0; i < a_arr.size(); i++){
    vector<int> ds = { a_arr[i]};
    find(ds, i, 0);
  }

  return 0; 
}