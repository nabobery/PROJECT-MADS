#include <iostream>
using namespace std;

int main() {
	int a,b,c;
	cin >> a >> b >> c;
	if((a > b || c > b) && (b > c || b > a)){
	    cout<<b<<"\n";
	}
	else if((b > a || c > a) && (a > c || a > b)){
	    cout<<a<<"\n";
	}
	else{
	    cout<<c<<"\n";
	}
	return 0;
}
