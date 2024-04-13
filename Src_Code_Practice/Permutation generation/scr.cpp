//C++ 
#include <bits/stdc++.h> 

using namespace std;

void printArr(vector<int> arr, int n, int index) {


  bool exist;
  if (index == n) {
    for (int i = 0; i < n; i++){
      cout << arr[i] << " ";
    }
    cout  << endl;
  }
  
  for (int i =1; i <=n; i++){
    exist = false;
    for (int j = 0; j < index ; j++){
        if(arr[j]==i){
          exist = true;
          break;
        }
    }
    if(exist == false){
      arr[index] = i;
      printArr(arr, n, index+1);
    }
  }

  
}

int main() {
  int n;
  cin >> n;
  
  vector<int> binary(n, 0); 
  printArr(binary, n, 0);
  
  return 0;
}
