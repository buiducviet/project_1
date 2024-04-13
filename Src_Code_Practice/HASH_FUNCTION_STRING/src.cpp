//C++ 
#include <bits/stdc++.h> 

using namespace std;
int n, m;
int calcPos(string s){
    int val = 0;
    int len = s.length();

    for (int i = 0; i < len; i++) {
        int t = s[i];
        val = ((val << 8) + t) % m;

    }
    return val;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s;
        cout << calcPos(s) << "\n";
    }
    return 0;
}
