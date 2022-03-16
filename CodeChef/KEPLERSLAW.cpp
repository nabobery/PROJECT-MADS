#include <iostream>
using namespace std;

int main() {
	int t,a,b,c,d;
	cin >> t;
	for(int i = 0; i < t; i++){
	    cin >> a >> b >> c >> d;
	    double r1 = (double)(a*a)/(c*c*c);
	    double r2 = (double)(b*b)/(d*d*d);
	    if(r1 == r2){
	        cout<<"YES\n";
	    }
	    else{
	        cout<<"NO\n";
	    }
	}
	return 0;
}
