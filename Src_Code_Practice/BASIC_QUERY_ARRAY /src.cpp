
#include <bits/stdc++.h> 
using namespace std;
int main() {
	int n;
    int m, k, temp=0;
    int x;
    cin >> n ;
    int mem, sum=0;
    vector<int> countm;
    vector<int> countk;
	vector<int> num;
    vector<string> queries;
	for(int i=0 ; i < n ; i++){
		cin >> mem;
        sum+=mem;
        num.push_back(mem);
	} 
    int max = num[0], min=num[0];
    for(int i = 1 ; i < n; i++){
        if(num[i]> max) max = num[i];
        if(num[i] < min ) min = num[i];
    }
    
    string s;
    while (s!="***")
    {
        cin >> s;
        if(s=="find-max-segment"){
            cin >> m >> k;  
            countm.push_back(m);
            countk.push_back(k);  
        }
        
        queries.push_back(s);   
    }
   
    for(int i = 0; i < queries.size();i++){
        if(queries[i] == "find-max") cout <<  max << endl;
        else if(queries[i] == "find-min") cout <<  min << endl;
        else if(queries[i] == "sum") cout << sum << endl;
        else if (queries[i] == "find-max-segment" ){
          
            int max_segment = num[countm[temp]-1];
            x = (countk[temp]> n) ? (n-1): (countk[temp]-1);
            for(int i = countm[temp]-1; i <= x ; i++){
                if(num[i] > max_segment){
                    max_segment = num[i];
                }
            }
            cout << max_segment << endl;
            temp++;
        };   
    }
	return 0;
}
