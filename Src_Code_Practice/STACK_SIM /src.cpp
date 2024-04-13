
//C++ 
#include <bits/stdc++.h> 
using namespace std;

int main(){
    stack<int> st;
    int x;
    string request;
    while (1){
        cin >> request;
        if(request=="#") break;
        if(request=="PUSH"){
            cin >> x;
            st.push(x);
        } else if(!st.empty()){
            cout << st.top() << endl;
            st.pop();
        } else {
            cout << "NULL" << endl;
        }
    }
    return 0;
}
