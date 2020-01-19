#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

struct Rectangle{
  int width, height;
};
typedef struct Rectangle REC;
vector<REC> recs;

REC area; 
REC createRectangle(int width, int height)
{
  REC rec;
  rec.width = width;
  rec.height = height;

  return rec; 
}

int n = 5; 
int main()
{
  for (int i = 0; i < n; i++){
    if(i == 0){
      REC resFirst = createRectangle(1, 1);
      recs.push_back(resFirst);
      area = resFirst;
      continue;
    }

    REC recLast = area;
    int c = max(recLast.width, recLast.height);
    REC rn = createRectangle(c, c);
    recs.push_back(rn);
    if (c == recLast.width){
      area = createRectangle(c, c + area.height);
      continue;
    }else if (c == recLast.height){
      area = createRectangle(c + area.width, c);
      continue;
    }
  }

  cout << area.width * area.height << endl;
  return 0;
}
