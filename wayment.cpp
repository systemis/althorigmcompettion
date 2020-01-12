#include <iostream>
#include <string>
#include <vector>

using namespace std;

int chia(int m, int n){
  if(m == 0)
    return 1; 
  if(n == 0)
    return 0;
  if(m < n){
    return chia(m, m);
  }else{
    return chia(m - n, n) + chia(m, n - 1);
  }
}

int main(){
  int m, n;
  cout << "Nhap so nguoi ";
  cin >> m;
  cout << endl
       << " Nhap so do vat ";
  cin >> n;
  int socach = chia(m, n);
  cout << socach << endl;
  return 0;
}