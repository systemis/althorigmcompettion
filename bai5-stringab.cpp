#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> s; 
int n, k;
bool checked[100]; 

void output(){
  for (int i = 0; i < s.size(); i++){
    cout << s[i] << " "; 
  }

  cout << endl;
}

void create(int j){
  if(j == k){
    output();
    return;
  }

  for (int i = 0; i < n; i++){
    if(checked[i])
      continue;
    
    checked[i] = true;
    s.push_back(i + 1);
    create(j + 1);
    checked[i] = false;
    s.pop_back();
  }
}

int main()
{
  cout << "Nhap n, k: " << endl;
  cin >> n >> k;
  for (int i = 0; i < n; i++){
    checked[i] = false; 
  }

  create(0);

  return 0;
}