#include <iostream>
#include <vector>

using namespace std;

vector<int> arr_a = {0, 0, 9, 2, 3, 7, 3, 1};
vector<int> arr_b = {4, 4, 0, 5, 0, 9, 0, 3, 10, 4, 8, 3};
vector<int> result;
vector<int> checked;
int main()
{
  if(arr_a.size() > arr_b.size()){
    vector<int> tmp = arr_a;
    arr_a = arr_b;
    arr_b = tmp;
  }

  for (int i = 0; i < arr_b.size(); i++){
    checked.push_back(false);
  };

  for (int i = 0; i < arr_a.size(); i++)
  {
    for (int j = 0; j < arr_b.size(); j++){
      if(arr_a[i] == arr_b[j] && checked[j] == false){
        checked[j] = true;
        result.push_back(arr_a[i]);
        break;
      }
    }
  }

  for (int i = 0; i < result.size(); i++){
    cout << result[i] << " ";
  }
  cout << endl;
  return 0;
}