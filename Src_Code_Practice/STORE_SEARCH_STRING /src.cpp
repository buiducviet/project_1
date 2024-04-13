//C++ 
#include <bits/stdc++.h>
using namespace std;

unordered_set<string> strings;

void input(){
    string str ="";
    while (str != "*"){
        cin >> str;
        strings.insert(str);
    }
}

void perform(){
    string cmd;
    string str;
    while(cmd != "***"){
        cin >> cmd;
        if(cmd == "find"){
            cin >> str;
            if(strings.find(str) != strings.end()) printf("1\n");
            else printf("0\n");
        } else if(cmd == "insert"){
            cin >> str;
            if(strings.find(str) != strings.end()) printf("0\n");
            else {
                strings.insert(str);
                printf("1\n");
            }
        }
    }
}
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    input();
    perform();
    return 0;
}
