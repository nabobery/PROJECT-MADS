#include <iostream>
#include <algorithm>
using namespace  std;

void solve(){
    int n, x;
    cin >> n >> x;
    int p[n];
    for(int i = 0; i < n;i++) cin >> p[i];
    sort(p, p + n);
    int l = 0, r = n - 1, result = 0;
    while(l <= r){
        if(p[l] + p[r] <= x){
            l++;
            r--;
        }
        else r--;
        result++;
    }
    cout<<result<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}

