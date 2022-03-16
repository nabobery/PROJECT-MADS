#include <iostream>
using namespace std;

int main() {
	int t,x,y,a,b;
	cin >> t;
	for(int i = 0; i < t;i++){
	    cin >> a >> b >> x >> y;
	    if(x*y >= a*b) cout<<"YES\n";
	    else cout<<"NO\n";
	}
	
	return 0;
}
