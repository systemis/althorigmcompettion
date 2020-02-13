#include <iostream>

using namespace std;

int main(){
  int n;
  cin >> n;
  long giaithua = 1;
  for (int i = 2; i <= n; i++){
    giaithua = giaithua * i; 
  }

  int uc = 2;
  for (int i =   2; i < giaithua - 1; i++){
    if(giaithua % i == 0){
      uc++;
    }
  }

  cout << uc << endl;
}
