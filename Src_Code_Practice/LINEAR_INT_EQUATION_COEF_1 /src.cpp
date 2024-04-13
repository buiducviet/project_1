#include<bits/stdc++.h>
using namespace std;

void printArr(vector<int> arr, int n,int m, int index, int sum) {
  
   if(index==n){
    if(sum==m) {
    for(int i = 0; i < n; i++){
      cout << arr[i] << " ";
    }
    cout << endl;
    } 
    return;
   }
   for(int i = 1; i <= m-sum; i++){
    arr[index]=i;
    printArr(arr,n,m,index+1,sum+i);
   }
}

int main() {
  int n, m;
  cin >> n >> m;
  
  vector<int> arr(n, 0); 
  printArr(arr, n, m, 0 , 0);
  
  return 0;
}
