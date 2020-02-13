#include <iostream>
#include <vector>
#include <math.h>

using namespace std; 

vector<vector<int>> nums; 

void show(){
  for (int i = 0; i < nums.size(); i++){
    cout << nums[i][0] << " " << nums[i][1] << endl;
  }
}
int main(){
  int a, b, c; 
  cin >> a >> b >> c;
  for (int i = 0; i < a; i++){
    vector<int> s;
    s.resize(2);
    cin >> s[0] >> s[1];
    nums.push_back(s);
  }

  for (int i = 0; i < b; i++)
  {
    vector<int> s;
    s.resize(2);
    cin >> s[0] >> s[1];
    nums.push_back(s);
  }

  for (int i = 0; i < c; i++)
  {
    vector<int> s;
    s.resize(2);
    cin >> s[0] >> s[1];
    nums.push_back(s);
  }

  vector<int> xucxac;
  int minn = 10000;
  for (int i = 0; i < nums.size(); i++)
  {
    int kens = nums[i][1];
    for (int j = i + 1; j < nums.size(); j++){
      if(nums[j][0] != nums[i][0])
        continue;
      kens += nums[j][1];
    }

    minn = min(minn, kens);
  }

  cout << minn << endl;

  // show();
}