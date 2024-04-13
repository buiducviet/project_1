//C++ 
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    Node(int x){
        value = x;
        leftchild = NULL;
        rightchild = NULL;
    }
    Node* leftchild;
    Node* rightchild;
};
unordered_set<int> listNode;
Node* head;
void Insert(Node* p, int x){

    if(x < p->value){
        if(p->leftchild == NULL){
            Node *tmp = new Node(x);
            p->leftchild = tmp;
        } else Insert(p->leftchild, x);
    } else {
        if(p->rightchild == NULL){
            Node *tmp = new Node(x);
            p->rightchild = tmp;
        } else Insert(p->rightchild, x);
    }
}

void input(){
    string str;
    int x;
    cin >> str >> x;
    head = new Node(x);
    listNode.insert(x);
    while(1){
        cin >> str;
        if(str == "#") break;
        scanf("%d", &x);
        if(listNode.find(x) == listNode.end()){
            listNode.insert(x);
            Insert(head, x);
        }
    }
}
void PreOrder(Node* p){
    printf("%d ", p->value);
    if(p->leftchild != NULL) PreOrder(p->leftchild);
    if(p->rightchild != NULL) PreOrder(p->rightchild);
}
void DeleteTree(Node* p) {
    if (p == NULL)
        return;
    DeleteTree(p->leftchild);
    DeleteTree(p->rightchild);
    delete p;
}

int main(){

    input();
    PreOrder(head);
    DeleteTree(head);
    return 0;
}
