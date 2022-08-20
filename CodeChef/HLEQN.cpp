#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t,x;
    cin >> t;
    while(t--){
        cin >> x;
        bool flag = false;
        for(int i = 1; i <= sqrt(x+4) - 2;i++){
            if((x - 2*i) % (i + 2) == 0){
                flag = true;
                break;
            }
        }
        cout<< (flag ? "YES\n" : "NO\n");
    }
	return 0;
}
