#include <iostream>
#include <vector> 

using namespace std;

vector<int> result; 
vector<int> nums = {3, 9, 4, 8, 6, 2, 1, 7, 10, 5};

void handling(int iPos, vector<int> getted){
  if (getted.size() > result.size())
  {
    result = getted;
  }else if(iPos >= nums.size()){
    return;
  }

  for (int i = iPos; i < nums.size(); i++){
    if(nums[i] > getted[getted.size() - 1]){
      getted.push_back(nums[i]);
      handling(i, getted);
      getted.pop_back();
    }
  }
}

int main(){
  handling(1, vector<int>{nums[0]});
  for (int i = 0; i < result.size(); i++){
    cout << result[i] << " ";
  }
  cout << endl;

  return 0;
}