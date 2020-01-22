#include <iostream> 
#include <vector>

using namespace std;

vector<int> arr = {4, 1, 0, 1, 1, 0, 1};
int maxScore = 0;

bool isEqual(vector<int> arrA, vector<int> arrB){
  int a = 0;
  int b = 0;
  for (int i = 0; i < arrA.size(); i++){
    a += arrA[i];
  }

  for (int i = 0; i < arrB.size(); i++){
    b += arrB[i];
  }

  return (a == b);
}

void outV(vector<int> arrA, vector<int> arrB){
  for (int i = 0; i < arrA.size(); i++)
  {
    cout << arrA[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < arrB.size(); i++)
  {
    cout << arrB[i] << " ";
  }
  cout << endl;
}

void solve(vector<int> comp, int iPos, int score){
  if(iPos >= comp.size() || comp.size() == 1){
    return; 
  }

  vector<int> arrA, arrB;
  for (int i = 0; i < iPos; i++){
    arrA.push_back(comp[i]);
    if(i == iPos - 1){
      for (int j = iPos; j < comp.size(); j++)
      {
        arrB.push_back(comp[j]);
      }
    }
  }

  

  if (!isEqual(arrA, arrB))
  {
    solve(comp, iPos + 1, score);
    return;
  }else{
    score += 1; 
    if (score > maxScore){
      maxScore = score;
    }
    solve(arrA, 1, score);
    solve(arrB, 1, score);
  }
}

int main()
{
  solve(arr, 1, 0);
  cout << maxScore << endl;
  return 0;
}