#include <iostream>
#include <vector>

using namespace std;

string str = "abcccbccabc";
vector<bool> checked;
int r = 0;

void process(string arr, int iPos){
  // char[] ds;
  // strcpy(ds, arr.c_str());
  if (arr.size() == 3)
  {
    if (arr == "abc")
    {
      r++;
    }
    return; 
  }

  for (int i = iPos; i < str.length(); i++){
    if(!checked[i]){
      checked[i] = true;
      arr += str[i];
      process(arr, i + 1);
      checked[i] = false;
      // arr = arr.substr(0, arr.size() - 1);
      arr.pop_back();
    }
  }
}

int main()
{
  for (int i = 0; i < str.length(); i++){
    checked.push_back(false);
  }

  process("", 0);
  cout << r << endl;

  return 0;
}