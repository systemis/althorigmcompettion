#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, maxL = 0;
string s, checked;
void nhap()
{
  cin >> n;
  string values[n];
  for (int i = 0; i <= n; i++)
  {
    getline(cin, values[i]);
    s += values[i];
  }

  cout << s << endl; 
}

int main(){
  nhap();
  char sA[s.length() + 1];
  strcpy(sA, s.c_str());

  for (int i = 0; i < s.length() + 1; i++){
    if (checked.find(tolower(sA[i])) != std::string::npos)
      continue;

    int count = 1;
    checked += tolower(sA[i]);
    for (int j = i + 1; j < s.length() + 1; j++)
    {
      if (tolower(sA[j]) == tolower(sA[i]))
      {
        count++;
      }
    }

    if (maxL < count){
      maxL = count;
    }
  }

  cout << maxL << endl;
  return 0;
}