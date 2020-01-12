#include <iostream>
#include <string>

using namespace std;

int weights[] = {1, 6, 2, 1, 1};
int maxL = 0; 
int main()
{
  int length = sizeof(weights) / sizeof(*weights);
  for (int i = 0; i < length; i++){
    int total = 0;
    for (int j = 0; j < length; j++)
    {
      if(weights[j] == weights[i]){
        continue; 
      }

      total += weights[j];
    }

    if (maxL < total)
    {
      maxL = total;
    }
  }

  cout << maxL << endl;
  return 0;
}