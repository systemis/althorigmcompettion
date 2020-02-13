#include <iostream>
#include <math.h>

using namespace std;

int UCLN2so(int a, int b)
{
  if (a % b == 0)
  {
    return b;
  }

  return UCLN2so(b, a % b);
};

int BCNN(int a, int b){
  return (a * b / UCLN2so(a, b));
}

int main(){
  long n;
  do
  {
    cin >> n;
  } while (n > pow(10, 12));

  for(int i =2; i < n; i++){
    for (int j = i; j < n; j++){
      if(BCNN(i, j) == n){
        cout << i << " " << j << endl;
        return 0;
      }
    }
  }


  return 0; 
}