#include <iostream>
#include<cmath>
using namespace std;

int main() {
	int t, n;
	cin >> t;
	for(int i = 0; i < t;i++){
	    cin >> n;
	    double result = 0.143*n;
	    result = pow(result,n);
	    int temp = (int) result;
	    if(result - temp < 0.5){
	        cout<<temp<<"\n";
	    }
	    else{
	        cout<<temp+1<<"\n";
	    }
	}
	return 0;
}
