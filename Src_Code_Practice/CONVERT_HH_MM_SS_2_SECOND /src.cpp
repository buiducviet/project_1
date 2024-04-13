#include <bits/stdc++.h> 
using namespace std;

int main() {
	string input;
	cin >> input;
	string hour, minute, second;
	int temp = 0;
	if(input.size() != 8)
	{
		cout << "INCORRECT";
		return 0;
	}	
	for ( int i = 0; i < input.size(); i++){
		if (i!=2 && i!=5){
			if(input[i]<'0' || input[i]>'9')
				temp++;
		}
		else {
			if(input[i]!=':')
				temp++;
		}
	}
	if(temp!=0){
		cout << "INCORRECT";
		return 0;
	}
	hour=input.substr(0,2);
	minute = input.substr(3,2);
	second = input.substr(6,2);
     if( stoi(hour)>23){
        cout << "INCORRECT";
		return 0;
    }
    if( stoi(minute) > 59){
        cout << "INCORRECT";
		return 0;
    }
     if(  stoi(second) > 59){
        cout << "INCORRECT";
		return 0;
    }
	cout << stoi(hour)*3600+ stoi(minute)*60 + stoi(second);
	return 0;
}
