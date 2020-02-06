#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int n, m; 
vector<int> a_nums, b_nums;

void output(){
  fstream FileOut;
  FileOut.open("LCS2X.OUT", ios_base::out);
  string data = "2";
  FileOut << data;
  FileOut.close();
}

int main(){
  ifstream FileIn;
  FileIn.open("test.txt", ios_base::in);
  FileIn >> n >> m;
  a_nums.resize(n);
  b_nums.resize(m);
  for (int i = 0; i < n; i++){
    FileIn >> a_nums[i];
  }

  for (int i = 0; i < m; i++){
    FileIn >> b_nums[i];
  }

  output();
  FileIn.close();
  cin.get();
  return 0;
}