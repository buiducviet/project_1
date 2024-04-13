//C++ 
#include <bits/stdc++.h> 
using namespace std;

int main(){
    stack<char> st;
    string Text;
    getline(cin, Text);
    char c;
    for (int i=0; i<Text.length(); ++i){
        c = Text[i];
        if (!st.empty()){
            if(c==')' && st.top()=='(') st.pop();
            else if(c=='}' && st.top()=='{') st.pop();
            else if(c==']' && st.top()=='[') st.pop();
            else st.push(c);
        } else st.push(c);
    }
    if(st.empty()) cout << 1;
    else cout << 0;
    
    return 0;
}
