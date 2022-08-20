#include <iostream>

using namespace std;

int main() {
    int t,x;
    cin >> t;
    while(t--){
        cin >> x;
        if(x <= 100) cout<<x<<"\n";
        else if(x > 100 && x <= 1000) cout<<x-25<<"\n";
        else if(x > 1000 && x <= 5000) cout<<x-100<<"\n";
        else cout<<x-500<<"\n";
    }
	return 0;
}
