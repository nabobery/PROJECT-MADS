#include <iostream>

using namespace std;

int main() {
    int t,n,x;
    cin >> t;
    while(t--){
        cin >> n >> x;
        if(x >= n) cout<<"0\n";
        else cout <<(n-x)/4 + ((n-x)%4 !=0)<<"\n";
    }
	return 0;
}
