#include <iostream>
#include <vector>
using namespace std;

void printBinaryStrings(vector<int> binary, int n, int index) {
  if (index == n) {
    for (int i = 0; i < n; i++) {
      cout << binary[i]; 
    }
    cout << endl;
    return;
  }
  
  // Thử với 0
  binary[index] = 0;
  printBinaryStrings(binary, n, index + 1);

  // Thử với 1
  binary[index] = 1;
  printBinaryStrings(binary, n, index + 1);
}

int main() {
  int n;
  cin >> n;
  
  vector<int> binary(n, 0); 
  printBinaryStrings(binary, n, 0);
  
  return 0;
}
