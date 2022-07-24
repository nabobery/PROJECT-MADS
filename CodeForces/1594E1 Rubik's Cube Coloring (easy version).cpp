#include <iostream>
using namespace std;

int mod = 1e9 + 7;

// number of ways is 6 * (4^(2^n) - 2)
// 6 is number of ways root can be colored and 4 is number of colors other nodes can be colored
void solve(){
    int n;
    cin >> n;
    long long int result = 6, y = 1,x = 4;
    for(int i = 0; i < n;i++){
        y *= 2;
    }
    y -= 2;
    // to mod (x^y)%p in O(logy)
    while(y > 0){
        if(y & 1) result = ((result*x) % mod);
        y = y >> 1;
        x = (x*x) % mod;
    }
    cout<<result<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}



