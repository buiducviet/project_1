#include <iostream>
#include <vector>
using namespace std;

void printBinaryStrings(vector<int> binary, int n, int index) {
  if (index == n) {
    // Kiểm tra xâu có 2 số 1 liên tiếp không
    bool valid = true;
    for (int i = 1; i < n; i++) {
      if (binary[i] == 1 && binary[i-1] == 1) {
        valid = false;
        break; 
      }
    }
    
    if (valid) {
      for (int i = 0; i < n; i++) {
        cout << binary[i];
      }
      cout << endl;
    }
    return;
  }
  
  // Thử với 0
  binary[index] = 0;
  printBinaryStrings(binary, n, index + 1);

  binary[index] = 1;
  printBinaryStrings(binary, n, index + 1);
  // Thử với 1
  
}

int main() {
  int n;
  cin >> n;
  
  vector<int> binary(n, 0); 
  printBinaryStrings(binary, n, 0);
  
  return 0;
}
