#include <iostream>
#include <vector>

using namespace std; 

int m = 6;
vector<vector<string>> arr = {{"JOIN-O-", "2"}, {"J", "TRAM-12"}};
vector<char> result;
void init(){
  string s1 = arr[0][0];
  string s2 = arr[0][1];
  string s = s1;
  for (int k = 0; k < m; k++){
    s += " ";
  }
  s += s2;
  for (int i = 0; i < s.length(); i++){
    result.push_back(' ');
  }
}

int main(){
  init();
  for (int i = 0; i < arr.size(); i++)
  {
    string s1 = arr[i][0];
    string s2 = arr[i][1];
    string s = s1;
    for (int k = 0;k < m; k++){
      s += " ";
    }
    s += s2;
    for (int j = 0; j < s.length(); j++)
    {
      if(result[j] != ' ' || s[j] == ' '){
        continue; 
      }

      result[j] = s[j];
    }
  }

  for (int i = 0; i < result.size(); i++){
    cout << result[i];
  }
  cout << endl;
  return 0;
}

