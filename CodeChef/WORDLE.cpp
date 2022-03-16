#include <iostream>
using namespace std;

int main() {
	int t;
	string S, T;
	cin >> t;
	for(int i = 0; i < t;i++){
	    cin >> S >> T;
	    for(int j = 0; j < 5;j++){
	        if(S[j] == T[j]) 
	            cout<<"G";
	        else
	            cout<<"B";
	    }
	    cout<<"\n";
	}
	return 0;
}
