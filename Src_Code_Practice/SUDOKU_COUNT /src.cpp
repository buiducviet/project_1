#include <bits/stdc++.h>
using namespace std;
int N= 9;
bool isValid(vector<vector<int> > board, int row, int col, int c) {
  for (int i = 0; i < 9; i++) {
    if (board[i][col] == c || board[row][i] == c)
      return false;
    if (board[3*(row/3) + i/3][3*(col/3) + i%3] == c)
      return false;
  }
  return true;
}
void solve(vector<vector<int> > &board, int &count) {
 for (int row = 0; row < N; row++) {
    for (int col = 0; col < N; col++) {
      if (board[row][col] == 0) {
        for (int num = 1; num <= 9; num++) {
          if (isValid(board, row, col, num)) {
            board[row][col] = num;
            solve(board, count);
            board[row][col] = 0; 
          }
        }
        return;
      }
    }
  }
  count++; 
}
int countSolutions(vector<vector<int> > board) {
  int solutions = 0;
  solve(board, solutions);
  return solutions;
}
int main() {
  vector<vector<int> > board(9, vector<int>(9, 0));
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cin >> board[i][j];
    }
  }
  int numSol = countSolutions(board);
  cout << numSol << endl;
  return 0;
}
