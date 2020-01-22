#include <iostream>
#include <vector>

using namespace std;
string s = "12:05:45PM";
int main()
{
  int h1 = (int)s[1] - '0';
  int h2 = (int)s[0] - '0';
  int hh = (h2 * 10 + h1);

  cout << hh << endl;
  if (s[8] == 'A')
  {
    if(hh == 12){
      s[0] = '0';
      s[1] = '0';
      for (int i = 8; i < s.length(); i++){
        s[i] = ' ';
      }
    }else{
      for (int i = 8; i < s.length(); i++)
      {
        s[i] = ' ';
      }
    }
  }else{
    if(hh == 12){
      s[0] = '1';
      s[1] = '2';
      for (int i = 8; i < s.length(); i++)
      {
        s[i] = ' ';
      }
    }else{
      hh = hh + 12;
      s[0] = to_string(hh)[0];
      s[1] = to_string(hh)[1];
      for (int i = 8; i < s.length(); i++)
      {
        s[i] = ' ';
      }
    }
  }

  cout << s << endl;
  return 0;
}