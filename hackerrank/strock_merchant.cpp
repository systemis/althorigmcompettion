#include <iostream>
#include <vector>

using namespace std; 

vector<int> stocks = {10, 20, 20, 10, 10, 30, 50, 10, 20};
vector<bool> checked;
int c = 0;
int main()
{
  for(int i =0; i < stocks.size(); i++){
    checked.push_back(false);
  }

  for(int i =0; i < stocks.size(); i++){
    int color = stocks[i];
    for(int j = 0; j < stocks.size(); j++){
      if(i == j || checked[i] || checked[j]) 
        continue; 
      if(stocks[j] == color){
        c += 1;
        checked[i] = true; 
        checked[j] = true; 
        break;
      }
    }
  }

  cout << c << endl;
  return 0;
}