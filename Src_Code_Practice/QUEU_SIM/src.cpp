//C++ 
#include <bits/stdc++.h> 
using namespace std;

int main(){
    queue<int> q;
    int x;
    string request;
    while (1){
        cin >> request;
        if(request=="#") break;
        if(request=="PUSH"){
            cin >> x;
            q.push(x);
        } else if(!q.empty()){
            cout << q.front() << endl;
            q.pop();
        } else {
            cout << "NULL" << endl;
        }
    }
    return 0;
}
