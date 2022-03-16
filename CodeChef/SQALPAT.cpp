#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	for(int i = 1; i <= n;i++){
	    if(i % 2 == 1){
	        for(int j = (i-1)*5 + 1; j <= 5*i;j++){
	            cout<<j<<" ";
	        }
	        cout<<"\n";
	    }
	    else{
	        for(int j = (i)*5; j > 5*(i-1);j--){
	            cout<<j<<" ";
	        }
	        cout<<"\n";
	    }
	}
	return 0;
}
