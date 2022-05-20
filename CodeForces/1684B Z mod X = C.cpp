#include <iostream>
using namespace  std;

void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    long long temp = b, x;
    for(int i = 1; ;i++){
        temp *= i;
        if(temp + a > c){
            x = temp + a;
            break;
        }
    }
    cout<<x<<" "<<b<< " "<< c<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}




