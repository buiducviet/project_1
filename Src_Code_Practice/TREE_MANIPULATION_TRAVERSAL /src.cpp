//C++ 
#include <bits/stdc++.h>
using namespace std;
struct Node{
    int id;
    Node(int n){
        id = n;
    }
    vector<Node*> child;
};
map<int, Node*> ListNode;
int root;

void MakeRoot(int u){
    Node* tmp = new Node(u);
    ListNode.insert({u, tmp});
}


void Insert(int u, int v){
    if (ListNode.find(u) == ListNode.end() &&
        ListNode.find(v) != ListNode.end()){
            Node* tmp = new Node(u);
            ListNode.insert({u, tmp});
            ListNode[v]->child.push_back(tmp);
    }
}


void PreOrder(Node* tmp){
    printf("%d ", tmp->id);
    if(!tmp->child.empty()){
        for(vector<Node*>::iterator it = tmp->child.begin(); it != tmp->child.end(); ++it){
            PreOrder(*it);
        }
    }
}


void InOrder(Node* tmp){
    if(!tmp->child.empty()){
        vector<Node*>::iterator it = tmp->child.begin();
        InOrder(*it);
        it++;
        printf("%d ", tmp->id);
        while(it != tmp->child.end()){
            InOrder(*it);
            it++;
        }
    } else printf("%d ", tmp->id);
}


void PostOrder(Node* tmp){
    if(!tmp->child.empty()){
        vector<Node*>::iterator it = tmp->child.begin();
        while(it != tmp->child.end()){
            PostOrder(*it);
            it++;
        }
    }
    printf("%d ", tmp->id);
}

void Request(){
    string request;
    while(1){
        int u, v;
        cin >> request;
        if(request == "*") break;
        if(request == "MakeRoot"){  
            scanf("%d", &u);
            root = u;
            MakeRoot(u);
        } else if(request =="Insert"){ 
            scanf("%d%d", &u, &v);
            Insert(u, v);
        } else if(request == "PreOrder"){  
            PreOrder(ListNode[root]);
            cout << endl;
        } else if(request == "InOrder"){  
            InOrder(ListNode[root]);
            cout << endl;
        } else if(request == "PostOrder"){  
            PostOrder(ListNode[root]);
            cout << endl;
        }
    }
}

int main(){
 
    Request();
    return 0;
}
