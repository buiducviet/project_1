//C++ 
#include <bits/stdc++.h>
using namespace std;

struct Person {
    string name;
    Person(string str){
        name = str;
    }
    vector<Person*> child;
};
map<string, Person*> Family;


void Add(string child, string parent){
    Person* c;
    if(Family.find(child) == Family.end()){
        c = new Person(child);
        Family.insert({child,c});
    } else c = Family[child];
    
    if(Family.find(parent) == Family.end()){  
        Person* p= new Person(parent);
        Family.insert({parent, p});
    }
    Family[parent]->child.push_back(c);
}

void input(){
    string child, parent;
    while(1){
        cin >> child;
        if(child == "***") break;
        cin >> parent;
        Add(child, parent);
    }
}

int count_tmp;
int max_gen;
void Generation(Person *p){
    if(!p->child.empty()){
        count_tmp ++;
        if(count_tmp > max_gen) 
            max_gen = count_tmp;
        vector<Person*>::iterator it= p->child.begin();
        while(it != p->child.end()){
            Generation(*it);
            it++;
        }
        count_tmp--;
    }
}

int Descendants(Person* p){
    if(p->child.empty()) return 0;
    else {
        int tmp_dants = p->child.size(); 
        vector<Person*>::iterator it= p->child.begin();
        while(it != p->child.end()){
            tmp_dants += Descendants(*it); 
            it++;
        }
        return tmp_dants;
    }
}

void solution(){
    string request, name;
    while (1){
        cin >> request;
        if(request == "***") break;
        cin >> name;
        if(request == "descendants"){
            cout << Descendants(Family[name]) << endl;
        } else if(request == "generation"){
            count_tmp = 0;
            max_gen = 0;
            Generation(Family[name]);
            cout << max_gen << endl;
        }
    }
}

int main(){

    input();
    solution();
    return 0;
}
