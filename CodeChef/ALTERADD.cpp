#include <iostream>

using namespace std;

int main() {
    int t,a,b;
    cin >> t;
    while(t--){
        cin >> a >> b;
        int diff = b - a;
        if(diff % 3 == 0 || diff % 3 == 1) cout<<"YES\n";
        else cout<<"NO\n";
    }

	return 0;
}
