#include <iostream>
using namespace std;

int main() {
	int a,b,c;
	cin >> a >> b >> c;
	double s = (double)(a+b+c)/2;
	if(s-a > 0 && s-b > 0 && s-c > 0){
	    cout<<"YES";
	}
	else{
	    cout<<"NO";
	}
	return 0;
}
