#include <iostream>
#include <string.h>

using namespace std;


int real_value(string y){
  if(stoi(y) <= 5){
    return stoi(y);
  }

  int total = 0;
  for (int i = 0; i < y.length(); i++){
    total += (int)y[i] - 48; 
  }

  return real_value(to_string(total / 2));
}

int main(){
  string x = "05042001";
  cout << real_value(x) << endl;
  return 0;
}