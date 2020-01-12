#include <iostream> 
#include <vector> 

using namespace std;

string root = "01010";
vector<char> rootChar;
int k = 2; 

string binary_getted(int i, string value){
  if(value.length() == k){
    return value; 
  }

  value += rootChar[i];
  return binary_getted(i + 1, value);
}

int main()
{
  char charA[root.length()];
  strcpy(charA, root.c_str());
  for (int k = 0; k < root.length(); k++)
  {
    rootChar.push_back(charA[k]);
  }

  for (int i = 0; i < rootChar.size() - k + 1; i++)
  {
    string val = binary_getted(i, "");
    cout << val << endl;
  }

  return 0;
}