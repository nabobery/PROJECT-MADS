#include <iostream>
using namespace std;

int main() {
	int t, x;
	cin >> t;
	for(int i = 0; i < t; i++){
	    int result = 0;
	    for(int j = 0; j < 3;j++){
	         cin >> x;
	        if(x > result) result = x;
	    }
	    cout<<result<<"\n";
	}
	return 0;
}
