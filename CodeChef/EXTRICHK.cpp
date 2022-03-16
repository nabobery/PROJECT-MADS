#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if(a == b && b == c){
	    cout<<"1\n";
	}
	else if((a == b && c < 2*a) || (b == c && a < 2*b) || (a == c && b < 2*c)){
	    cout<<"2\n";
	}
	else if(a != b && b != c && c != a && (a + b > c && b + c > a && c+a > b)) {
	    cout<<3<<"\n";
	}
	else{
	    cout<<-1<<"\n";
	}
	return 0;
}
