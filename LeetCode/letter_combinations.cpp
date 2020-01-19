#include <iostream>
#include <vector>
#include <string>

using namespace std;
class ClassName
{
  // Khai báo thuộc tính: giống khai báo biến
  // Khai báo phương thức: Giống khai báo hàm
  // private, protected, public
  // private: Chỉ sử dụng trong class
  // public: Bên ngoài có thể sử dụng được.

public:
  string digits = "23";
  vector<int> nums;
  vector<string> result;
  vector<vector<char>> table = {
      {'a', 'b', 'c'},
      {'d', 'e', 'f'},
      {'g', 'h', 'i'},
      {'j', 'k', 'l'},
      {'m', 'n', 'o'},
      {'p', 'q', 'r', 's'},
      {'t', 'u', 'v'},
      {'w', 'x', 'y', 'z'}};
  
  void combination(int iPos, vector<char> chuoi)
  {
    if (chuoi.size() == digits.length()){
      string r = "";
      for (int i = 0; i < chuoi.size(); i++){
        r += chuoi[i];
      }

      result.push_back(r);
      return;
    }

    vector<char> posible = table[nums[iPos]];
    for (int i = 0; i < posible.size(); i++){
      chuoi.push_back(posible[i]);
      combination(iPos + 1, chuoi);
      chuoi.pop_back();
    }
  }

  vector<string> letterCombinations(string d){
    digits = d; 
    char charA[digits.length()];
    strcpy(charA, digits.c_str());
    for (int i = 0; i < sizeof(charA) / sizeof(*charA); i++)
    {
      nums.push_back((int)charA[i] - 48 - 2);
    }

    combination(0, vector<char>());
    for (int i = 0; i < result.size(); i++)
    {
      cout << result[i] << endl;
    }

    return result;
  }
};

int main(){
  ClassName cl;
  cl.letterCombinations("23");
  return 0;
}