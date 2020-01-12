#include <iostream>
#include <string>

using namespace std;

int n; 

void xuat(){
  cout << "Mot cach chon " << endl;
}

int choice(int num, int turn, int k){
  if(num <= 0){
    xuat();
    return 0;
  }

  for (int i = k; i > 0; i--)
  {
    if(i == 1 && num == n){
      xuat();
      break;
    }

    for (int j = 1; j <= n; j ++){
      if(i * j > n){
        break;
      }else if(turn <= 1){
        if(i * j == n){
          xuat();
          break;
        }
        cout << j << " " << i << endl; 
        choice(num - (i * j), turn + 1, k - 1);
      }else{
        if (i * j == num){
          cout << j << " " << i << endl;
          choice(0, turn + 1, k - 1);
        }
      }
    }
  }

  return 1; 
}

int main(){
  cout << "Nhap n: " << " ";
  cin >> n;

  choice(n, 1, 3);

  return 0;
}