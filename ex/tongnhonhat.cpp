#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main(){
  vector<int> a_arr, b_arr;
  int n, m; 
  cin >> n >> m;
  a_arr.resize(n);
  b_arr.resize(m);
  for (int i = 0; i < n; i++){
    cin >> a_arr[i];
  }
  for (int i = 0; i < m; i++){
    cin >> b_arr[i];
  }

  int minA = a_arr[0];
  for (int i = 0; i < n; i++){
    if(minA > a_arr[i]){
      minA = a_arr[i];
    }
  }


  long total = 100000000000;
  for (int j = 0; j < m; j++){
    if (abs(minA + b_arr[j]) < total)
    {
      total = abs(minA + b_arr[j]);
    }
  }

  cout << total << endl;
  return 0;
}