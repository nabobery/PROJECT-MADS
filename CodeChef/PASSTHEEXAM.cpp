#include <iostream>

using namespace std;

int main() {
    int t,a,b,c;
    cin >> t;
    while(t--){
        cin >> a >> b >> c;
        if(a >= 10 && b >= 10 && c >= 10){
            if(a+b+c >= 100) cout<<"PASS\n";
            else cout<<"FAIL\n";
        }
        else cout<<"FAIL\n";
    }
	return 0;
}
