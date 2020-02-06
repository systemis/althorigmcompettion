#include <iostream>

using namespace std;

// long  n = 12814453125; 
long  n = 45; 

void phantich(long ns){
  int nums[3] = {3, 5, 7};
  int length = 3;
  int i = 0, dem = 0, count = 0; 
  while(i < length){
    dem = 0;
    if(nums[i] > ns){
      break;
    }
    count++;
    // if (ns % nums[i] != 0){
    // }

    while (ns % nums[i] == 0)
    {
      count += 1;
      dem += 1;
      ns = ns / nums[i];
      }

    if (dem)
    {
      cout  << nums[i];
      if(dem > 1){
        cout << "^" << dem; 
      }

      if(ns > nums[i]){
        cout << " * ";
      }
    }

    i += 1;
  }

  cout << endl;
  cout << count << endl;
  if (ns != 1)
  {
    // cout << " K " << endl;
  }else{

  }
}

int main(){
  phantich(n);
  return 0;
}