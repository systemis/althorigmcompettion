#include <iostream>
#include <vector> 

using namespace std;

vector<int> values = {3, 4, 5, 1, 7, 8, 9, 2, 4, 6, 10, 23, 45, 92, 43, 56, 42, 78, 95, 79, 73, 74, 66, 68, 56};
vector<string> gettedstring = {};

int findIndex(vector<int> arr, int val){
  for (int i = 0; i < arr.size(); i++){
    if(arr[i] == val){
      return i; 
    }
  }
    
  return -1;
}

int findIndexS(vector<string> arr, string val){
  for (int i = 0; i < arr.size(); i++){
    if (arr[i] == val){
      return i;
    }
  }

  return -1;
}

void tryget(vector<int> triagle){
  if(triagle.size() == 3){
    for (int i = 0; i < triagle.size(); i++){
      for (int j = 0; j < triagle.size(); j++){
        if(triagle[j] > triagle[i]){
          int tmp = triagle[i];
          triagle[i] = triagle[j];
          triagle[j] = tmp;
        }
      }
    }

    if (triagle[0] + triagle[1] > triagle[2]){
      string s; 
      for (int k = 0; k < triagle.size(); k++){
        s += to_string(triagle[k]);
      }

      if(findIndexS(gettedstring, s) == -1){
        gettedstring.push_back(s);
        for (int k = 0; k < triagle.size(); k++){
          cout << triagle[k] << " ";
        }
        cout << endl;
      }
    }

    return;
  }

  for (int i = 0; i < values.size(); i++){
    if(findIndex(triagle, values[i]) == -1){
      triagle.push_back(values[i]);
      tryget(triagle);
      triagle.pop_back();
    }
  }
}

int main(){
  vector<int> test = {};
  tryget(test);
  cout << gettedstring.size() << endl;
  return 0;
}