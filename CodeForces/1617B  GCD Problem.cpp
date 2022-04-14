#include <iostream>
using namespace  std;

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}

void solve(){
    int n;
    cin >> n;
    int temp = n - 3;
    for(int i  = 2; ;i++){
        if(gcd(i,temp) == 1){
            cout<<i<<" "<<temp<<" "<<1<<"\n";
            break;
        }
        temp--;
    }
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

