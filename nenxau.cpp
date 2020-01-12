#include <iostream> 
#include <vector>

using namespace std;

int m = 6, m1 = 2, m2 = 1, r = 1; // Nhập từ bàn phím
int minr = 10 * 9;
string ut, vt; 
string rip = "CABAAC"; // chuỗi nhập từ bàn phím 
vector<char> bundle;

// Hàm giải nén theo định luật fibonacci ;
string decode(string us, string vs, int k)
{
  string decoderesult = "";
  for (int i = 2; i < k - 1; i++)
  {
    decoderesult = vs + us;
    us = vs;
    vs = decoderesult;
  }

  return decoderesult;
}

// Hàm kiểm tra xem phần tử đã có trong mạng hay là chưa
int findindex(vector<int> arr, int value){
  for (int i = 0; i < arr.size(); i++){
    if(arr[i] == value)
      return i;
  }
  return -1;
}

// Tính số lỗi sau khi giải nén
int find_error(string a, string b){
  int error = 0;
  char charA[a.length()], charB[b.length()];
  strcpy(charA, a.c_str());
  strcpy(charB, b.c_str());

  for (int i = 0; i < sizeof(charA)/sizeof(*charA); i++){
    if(charA[i] != charB[i]){
      error += 1;
    }
  }

  return error;
}

// Lấy us và vs từ rip theo m1 và m2 (lấy bộ nén) 
// -> giải nén 
// -> tìm lỗi so với RIP 
// -> so sánh lỗi
void handling(string root)
{
  string us = "", vs = "";
  char charRoot[root.length()];
  strcpy(charRoot, root.c_str());
  for (int i = 0; i < m1 + m2; i++){
    if(i < m2){
      vs += charRoot[i];
      continue;
    }

    us += charRoot[i];
  }

  string decodestring = decode(us, vs, m);
  int err = find_error(root, decodestring);
  minr = min(err, minr);
}

// Thay đổi r kí tự trong m1 + m2 kí tự đầu tiên của rip để tìm lỗi nhỏ nhất
void doi(vector<int> checkeds, int ri, string s){
  char charS[s.length()];
  strcpy(charS, s.c_str());

  if(ri > r){
    return;
  }else{
    handling(s);
  }

  for (int i = 0; i < m1 + m2; i++)
  {
    if(findindex(checkeds, i) == -1){ // Kiểm tra xem vị trị thứ i đã được hoán đổi hay chưa, nếu chưa thì tiếp tục xử lý
      checkeds.push_back(i); // Đánh dấu vị trí thứ i đã hoán đổi
      for (int j = 0; j < bundle.size(); j++){
        if(bundle[j] == charS[i])
          continue;
        charS[i] = bundle[j]; // Hoán đổi vị trí thứ i với m1 + m2 kí tự đầu tiên của rip;
        doi(checkeds, ri + 1, charS); // tăng ri và tiếp tục hoán đổi với vị trí khác i; 
      }

      // Xoá i ra khỏi vị trí đánh dấu và quay lui
      checkeds.pop_back();
    }
  }
}

int main(){
  char charRip[rip.length()];
  strcpy(charRip, rip.c_str());
  for (int i = 0; i < m1 + m2; i++){
    bundle.push_back(charRip[i]);
  }

  doi(vector<int>(), 0, rip);

  cout << minr << endl;
  return 0;
}