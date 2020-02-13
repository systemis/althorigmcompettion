#include <iostream>
#include <vector>

using namespace std; 

bool check_songuyento(int n){
  for (int i = 2; i < n; i++){
    if(n % i == 0 ){
      return false;
    }
  }

  return true;
}

int main(){
  vector<int> test = {11};
  for (int k = 0; k < test.size(); k++){
    int n = test[k], count = 0;
    int total = 0; 
    for (int i = 2; i < 100000; i++)
    {
      if(!check_songuyento(i))
        continue;
      cout << i << endl;
      total += i;
      count++;
      if(count == n){
        break;
      }
    }

    cout << total << endl;
  }

  return 0;
}