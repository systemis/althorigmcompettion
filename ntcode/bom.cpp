#include <iostream>
#include <vector> 

using namespace std;

int maxWeight = -10,  way = 0, bw = 7;
vector<int> golds = {4, 6, 2};

int findIndex(vector<int> arr, int value){
  for (int i = 0; i < arr.size(); i++){
    if(arr[i] == value)
      return i;
  }
  return -1; 
}

void get(int weight, int iPos){
  if (weight > maxWeight && weight <= bw){
    maxWeight = weight; 
    way = 0;
  }

  if(weight > 0 && weight == maxWeight){
    way += 1; 
  }

  if(weight > bw){
    return;
  }

  for (int i = iPos; i < golds.size(); i++){
    weight += golds[i];
    get(weight, i + 1);
    weight -= golds[i];
  }
}

int main(){
  int n = 0;
  cin >> n >> bw;
  golds = {};
  for (int i = 0; i < n; i++)
  {
    int s;
    cin >> s;
    golds.push_back(s);
  }

  get(0, 0);
  cout <<  maxWeight << endl << way << endl;
  return 0;
}