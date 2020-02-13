#include <iostream>
#include <vector>
#include <math.h>
#include <cstdlib>

using namespace std;
int n, m;
vector<long> rs, vs; 

void random_rs(int n){
  for (int i = 0; i < n; i++){
    rs[i] = rand() % 1000; 
  }
}

void random_vs(int n)
{
  for (int i = 0; i < n; i++)
  {
    vs[i] = rand() % 1000000;
  }
}

int main(){
  cin >> n >> m;
  rs.resize(n);
  vs.resize(m);
  random_rs(n);
  random_vs(m);
  // for (int i = 0; i < n; i++)
  // {
  //   cin >> rs[i];
  // }
  
  // for (int i = 0; i < m; i++)
  // {
  //   cin >> vs[i];
  // }

  long total = 0;
  for (int i = 0; i < n; i++){
    long r = 0; 
    for (int j = 0; j < m; j++)
    {
      r += abs(vs[j] - rs[i]);
    }

    if(total < r){
      total = r;
    }
  }

  cout << total << endl;
}