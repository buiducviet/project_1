//C++ 
#include <bits/stdc++.h> 

using namespace std;

int main() {
  int n, M;
  cin >> n >> M;

  set<int> s;
  int result = 0;
/* Bùi Đức Việt 20215513 */
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
/* Kiểm tra nếu trong tập hợp có phần tử bằng M-x thì tăng đếm lên 1*/
    if (s.find(M - x) != s.end()) {
      result++;
    }

    s.insert(x);
  }

  cout << result << endl;

  return 0;
}
