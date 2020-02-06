#include <iostream>

using namespace std; 

string convert_hex(int sodu){
  switch(sodu){
    case 0: 
    case 1: 
    case 2:
    case 3: 
    case 4: 
    case 5: 
    case 6: 
    case 7: 
    case 8: 
    case 9:
      return to_string(sodu);
    case 10:
      return "A";
    case 11:
      return "B";
    case 12:
      return "C";
    case 13:
      return "D";
    case 14:
      return "E";
    case 15:
      return "F";
  }

  return "A";
}

int main(){
  int n = 18;
  if(n < 16){
    cout << convert_hex(n) << endl;
    return 0;
  }

  string result = "";
  while(n != 0){
    int sodu = n % 16;
    n = n / 16;
    result = convert_hex(sodu) + result;
  }

  cout << result << endl;
  return 0;
}