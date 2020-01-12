#include <iostream>
#include <string>

using namespace std;

void bai1(){
  int k, maxL = 1;
  int candys[] = {1, 2, 3, 3, 4, 6, 34, 5};

  cout << "Nhap vao so K" << endl;
  cin >> k;
  int length = sizeof(candys) / sizeof(*candys);
  for (int i = 0; i < length; i++)
  {
    int total = candys[i], c = 0;
    for (int j = i + 1; j < length; j++)
    {
      total += candys[j];
      c++;
      if ((int)total / c == k)
      {
        maxL = c;
      }
    }
  }
  cout << maxL << endl;
}

bool checked[100];
int n;
string s; 

int hoanvi(int j){
  if (j == n)
  {
    cout << s << "  " << endl;
    return 0;
  }

  for (int i = 0; i < n; i++){
    if(checked[i] == false){
      checked[i] = true;
      s += to_string(i + 1);
      hoanvi(j + 1);
      s.erase(j, 1);
      checked[i] = false;
    }
  }

  return 1;
}

void baitaphoanvi(){
  cout << "Nhap vao so n" << endl;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    checked[i] = false;
  }

  hoanvi(0);
}

int main()
{
  return 0;
}
