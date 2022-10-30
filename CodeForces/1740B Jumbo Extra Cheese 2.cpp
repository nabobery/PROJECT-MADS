#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#pragma GCC optimize("Ofast")

#define ll long long int

void solve(){
    int n,a,b,y = 0;
    long long int result = 0;
    cin >> n;
    for(int i = 0; i < n;i++){
        cin >> a >> b;
        result += min(a,b);
        y = max(y,max(a,b));
    }
    result *= 2;
    result += 2*y;
    cout<<result<<"\n";
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

