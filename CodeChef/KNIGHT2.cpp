#include <iostream>

using namespace std;

int main() {
    int t,x_1,y_1,x_2,y_2;
    cin >> t;
    while(t--){
        cin >> x_1 >> y_1 >> x_2 >> y_2;
        if((x_1+y_1-x_2-y_2)%2 == 0) cout<<"YES\n";
        else cout<<"NO\n";
    }
	return 0;
}
