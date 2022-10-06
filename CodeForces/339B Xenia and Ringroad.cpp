#include <iostream>
using namespace std;

#pragma GCC optimize("Ofast")

void solve(){
    int n, m,prev,x;
    long long int result = 0;
    cin >> n >> m;
    cin >> prev;
    result += (prev-1);
    for(int i = 1; i < m;i++){
        cin >> x;
        if(prev <= x) result += (x - prev);
        else result += (n + (x - prev));
        prev = x;
    }
    cout<<result<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
