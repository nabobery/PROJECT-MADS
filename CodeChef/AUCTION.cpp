#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t,a,b,c;
    cin >> t;
    while(t--){
       cin >> a >> b >> c;
       if(max(a,b) == a){
            if(max(a,c) == a) cout<<"Alice\n";
            else cout<<"Charlie\n";
        }
        else{
            if(max(b,c) == b) cout<<"Bob\n";
            else cout<<"Charlie\n";
        }
    }
	return 0;
}
