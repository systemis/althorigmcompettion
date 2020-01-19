#include <iostream>
#include <vector>

using namespace std;

vector<int> dumbel = {1, 2, 5, 10, 15, 20};
vector<int> dumbel_now = {2, 2, 7};
int taget = 14;
int mincount = 10 * 9; 

int total(vector<int> arr){
  int tong = 0;
  for (int i = 0; i < arr.size(); i++){
    tong += arr[i];
  }

  return tong;
}

void popback(int count, vector<int> d){
  if(total(d) == taget){
    if(mincount > count){
      mincount = count;
    }
    return;
  }else if (total(d) > taget && count > 0){
    return;
  }

  for (int i = 0; i < dumbel.size(); i++){
    d.push_back(dumbel[i]);
    popback(count + 1, d);
    d.pop_back(); 
  }

  if(count == 0){
    int c = count; 
    for (int i = d.size() - 1; i >= 0; i--)
    {
      c++; 
      d.pop_back();
      popback(c, d);
    }
  }
}

int main()
{
  popback(0, dumbel_now);
  // for (int i = 0; i < dumbel_now.size(); i++){
    // cout << dumbel_now[i] << endl;
  // }
  cout << mincount << endl;
  return 0;
}