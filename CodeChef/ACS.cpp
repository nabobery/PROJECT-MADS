#include <iostream>

using namespace std;

int main() {
    int t,x;
    cin >> t;
    while(t--){
        cin >> x;
        int a = x/100;
        int b = (x - 100*a);
        if(a + b > 10) cout<<-1<<"\n";
        else cout<<a+b<<"\n";
    }
	return 0;
}
