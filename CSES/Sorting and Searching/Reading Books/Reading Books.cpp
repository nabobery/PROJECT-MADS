#include <iostream>
using namespace std;

void solve(){
    int n,x, max = -1;
    long long int sum = 0;
    cin >> n;
    for(int i = 0; i < n;i++){
        cin >> x;
        sum += x;
        if(x > max) max = x;
    }
    if(sum <= 2*max) cout<<2*max<<"\n";
    else cout<<sum<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}



