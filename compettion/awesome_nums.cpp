#include <iostream>  
#include <math.h>
#include <vector>
#include <cstdlib>

using namespace std; 

vector<int> tests = {1, 2, 89032, 23, 324235, 32482, 9823, 74682, 78932};

bool isPrimeNum(int num){
  for (int i = 2; i < num / 2; i++){
    if(num % i == 0){
      return false;
    }
  }

  return true; 
}

bool isAwesome(int num){
  int c = 0;
  string s = to_string(num);
  for (int i = 0; i < s.length(); i++)
  {
    c += pow((int)s[i] - 48, 2);
  }

  return isPrimeNum(c);
}

void initTets(){
  for (int i = 0; i < 1000; i++){
    tests.push_back(rand() % 50000 + 1);
  }
}

int main(){
  // cout << isPrimeNum(251) << endl;
  // return 0;
  initTets();
  for (int i = 0; i < tests.size(); i++)
  {
    int n = tests[i];
    int mx = 10 + n;
    int aws = 0;
    int c = 0; 

    for (int k = 11; k <= mx; k++){
      if (isAwesome(k))
      {
        c += 1; 
        if(c == n){
          aws = k;
          break; 
        }
      }
      if (k == mx && aws == 0)
      {
        mx += 1;
        continue;
      }
    }

    cout << aws << endl;
  }

  return 0; 
}