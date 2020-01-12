#include <iostream>
#include <vector>

using namespace std;

vector<string> queget;
vector<string> values = {
    "hoc Tot", "hoc gioi", "hoc sinh", "tin hoc", "hoa hoc", "sinh hoc",
    "ngoai ngu", "lich su", "dia ly", "cong dan"};

bool checked[100];

int getIndex(vector<int> arr, int value){
  for (int i = 0; i < arr.size(); i++){
    if(arr[i] == value){
      return i;
    }
  }

  return -1; 
}

void maintaining(vector<int> checkedlist){
  int nc = 0;
  string pos = values[checkedlist[checkedlist.size() - 1]];
  char cA[pos.length()];
  strcpy(cA, pos.c_str());

  
  for (int i = 0; i < values.size(); i++)
  {
    if(values[i] == pos || getIndex(checkedlist, i) != -1){
      continue;
    }

    char cc[values[i].length()];
    strcpy(cc, values[i].c_str());
    if (cc[0] == cA[sizeof(cA) / sizeof(*cA) - 1])
    {
      nc += 1; 
      checkedlist.push_back(i);
      maintaining(checkedlist);
      checkedlist.pop_back();
    }
  }

  if (nc == 0)
  {
    for (int k = 0; k < checkedlist.size(); k++){
      cout << values[checkedlist[k]] << " ";
    }

    cout << endl;
  }
}

int main()
{
  for (int i = 0; i < values.size(); i++){
    checked[i] = false;
  }

  for (int i = 0; i < values.size(); i++){
    checked[i] = true;
    vector<int> list = {i};
    maintaining(list);
  }

  return 0;
}