#include <iostream>
using namespace std;

int main() {
	int t, n, x,a,b,c;
	cin >> t;
	for(int i = 0; i < t;i++){
	    bool flag = false;
	    cin >> n >> x;
	    a = x%3 ? (x/3 +1) : x/3;
        for(b = 0; b + a <= n;b++){
            if((3*a - b) < 0) continue;
            if((3*a - b) == x){
                flag = true;
                break;
            }
        }
	    if(flag){
	        cout<<"YES\n";
	        cout<<a<<" "<<b<<" "<<n-a-b<<"\n";
	    }
	    else cout<<"NO\n";
	}
	return 0;
}
