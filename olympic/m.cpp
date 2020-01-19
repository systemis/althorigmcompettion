#include <iostream>
#include <vector>

using namespace std;

int m = 10, result = 0;
vector<int> coins = {1, 2, 3, 4, 5};

void hh(int iPos, int total){
  if(iPos >= coins.size()){
    return;
  }
  if(total == m){
    cout << m << " ";
    return;
  }
  for (int i = iPos; i < coins.size(); i++){
    total += coins[i];
    hh(iPos + 1, total);
    total -= coins[i];
  }
}

int main()
{
  hh(0, 0);
  return 0;
}