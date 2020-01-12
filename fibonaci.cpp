#include <iostream>

using namespace std;

int fibo(int k){
  if(k <= 2){
    return k;
  }

  return fibo(k - 1) + fibo(k - 2);
}

void initday(int n){
  int a = 1;
  int b = 2; 
  for (int i = 1; i <= n; i++)
  {
    if(i <= 2){
      cout << i << " ";
      continue;
    }

    int c = a + b;
    a = b;
    b = c;
    cout << c << " ";
  }

  cout << endl;
}

int main(){
  int result = fibo(10);
  initday(10);
  return 0;
}