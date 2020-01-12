#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> alphal = {
    {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'}, 
    {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'},
    {'z', 'x', 'c', 'v', 'b', 'n', 'm'}};

vector<string> inputValues = {"hello", "alaska", "dad", "peace"};

bool checked(string teststring, int poscheck, int row){
  char charA[teststring.length()];
  strcpy(charA, teststring.c_str());
  char checkchar = charA[poscheck];
  for (int i = 0; i < alphal.size(); i++){
    for (int j = 0; j < alphal[j].size(); j++){
      if(alphal[i][j] == checkchar){
        if(poscheck == 0){
          return checked(teststring, poscheck + 1, i);
        }else if(row !=i){
          return false;
        }
      }
    }
  }

  if (poscheck == teststring.length() - 1)
  {
    return true;
  }else
  {
    return checked(teststring, poscheck + 1, row);
  }
}

int main()
{
  for (int i = 0; i < inputValues.size(); i++){
    bool check = checked(inputValues[i], 0, 0);
    cout << check << endl;
  }

  return 0;
}