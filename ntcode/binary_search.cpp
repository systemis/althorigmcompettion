#include <iostream> 
#include <vector>

using namespace std;

int n =6, m = 5;
vector<int> result; 

int main(){
  for (int i = 1; i <= n; i++){
    int total = i;
    vector<int> p = {i};
    for (int j = i + 1; j <= n; j++)
    {
      total += j;
      p.push_back(j);
      if(total == m && p.size() > result.size()){
        result = p;
        break;
      }
    }
  }

  cout << result[0] << " " << result[result.size() - 1] << endl;
  return 0;
}