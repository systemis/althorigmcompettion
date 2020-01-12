#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> values = {"<<<", "<=<=>", "<<>"};

bool checked(char Dau, int a, int b){
  switch(Dau){
    case '<':
      return a < b; 
    case '>':
      return a > b;
    case '=': 
      return a = b; 
  }

  return false; 
}

string format(string value)
{
  char charA[value.size() + 1];
  strcpy(charA, value.c_str());
  int length = sizeof(charA) / sizeof(*charA);

  for (int i = 0; i < length; i++)
  {
    if(charA[i] == '<' || charA[i] == '='){
      continue;
    }

    if(i == length - 2 && charA[i] == '>'){
      charA[i] = '<';
    }

    for (int j = i + 1; j < length; j++)
    {
      if(charA[j] == '<'){
        charA[i] = '<';
        charA[j] = '<';
        j = length; 
      }
    }
  }

  return charA; 
}

string formatequal(string value){
  char charA[value.length()];
  strcpy(charA, value.c_str());
  vector<char> charor;
  for (int i = 0; i < sizeof(charA) / sizeof(*charA); i++){
    charor.push_back(charA[i]);
  }

  for (int i = 1; i < charor.size() - 1; i++){
    if(charor[i] != '='){
      continue;
    }

    char a = charor[i - 1];
    char b = charor[i + 1];
    if(a == b){
      charor.erase(charor.begin() + i);
    }else{
      charor.erase(charor.begin() + i);
      charor.erase(charor.begin() + i);
    }
  }

  string s = "";
  for (int i = 0; i < charor.size(); i++)
  {
    s += charor[i];
  }
  return format(s);
}

int main(){
  for (int i = 0; i < values.size(); i++){
    if(values[i].find("=") != -1){
      values[i] = formatequal(values[i]);
    }else{
      values[i] = format(values[i]);
    }

    cout << values[i].length() + 1 << endl;
  }

  return 0;
}