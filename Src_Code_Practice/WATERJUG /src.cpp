#include <bits/stdc++.h>
using namespace std;

int A, B, C;
int min_steps = 1e9;
int steps=0;
queue<pair<int,int>> q;
bool marks[1000][1000]={false};
pair<int, int> before[1000][1000]; //before[i][j] Chứa bước trước đó của {i, j}
int tmp_a, tmp_b;

void FindNext(int a, int b){
    if(a < A){
        if(!marks[A][b]) {
            q.push({A,b});
            before[A][b] = {a,b};
        }
        if(b>0){ 
            if(a + b <= A && !marks[a+b][0]) {
                q.push({a+b, 0});
                before[a+b][0] = {a,b};
            }
            if(a + b > A && !marks[A][a+b-A]) {
                q.push({A, a+b-A});
                before[A][a+b-A] = {a,b};
            }
            if(!marks[a][0]) {
                q.push({a,0});
                before[a][0] = {a,b};
            }
        }
    }
    if(b < B){
        if(!marks[a][B]) {
            q.push({a,B}); 
            before[a][B] = {a,b};
        }
        if(a>0){ 
            if(a + b <= B && !marks[0][a+b]) {
                q.push({0, a+b});
                before[0][a+b] = {a,b};
            }
            if(a + b > B && !marks[a+b-B][B]) {
                q.push({a+b-B, B});
                before[a+b-B][B] = {a,b};
            }
            if(!marks[0][b]) {
                q.push({0,b});
                before[0][b]= {a,b};
            }
        }
    }
}

void solution(int a, int b){
    if (a!=0 || b !=0){
        tmp_a = before[a][b].first;
        tmp_b = before[a][b].second;
        steps++;
        solution(tmp_a, tmp_b);
    } else cout << steps;
}

void Pour(int a, int b){
    q.pop();
    if(a == C || b == C) solution(a, b);
    else {
        FindNext(a, b);
        if (!q.empty()){
            tmp_a = q.front().first;
            tmp_b = q.front().second;
            marks[tmp_a][tmp_b] = true;
            Pour (tmp_a, tmp_b);
        } else cout << -1;
    }
}

int main(){
    cin >> A >> B >> C;
    marks[0][0] = true;
    q.push({0, 0});
    Pour(0, 0);
    return 0;
}
