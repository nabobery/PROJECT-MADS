#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#pragma GCC optimize("Ofast")

#define ll long long int

void solve(){
    int n,m,x,y,count = 0;
    cin >> n >> m;
    vector<bool> r(8,false), c(8,false);
    bool flag1 = false, flag2 = false;
    for(int i = 0; i < m;i++){
        cin >> x >> y;
        if(!r[x-1] && !c[y-1]){
            r[x-1] = true;
            c[y-1] = true;
        }
    }
    for(int i = 0; i < n;i++){
        if(!r[i]){
            flag1 = true;
            break;
        }
    }
    for(int i = 0; i < n;i++){
        if(!c[i]){
            flag2 = true;
            break;
        }
    }
    if(flag1 && flag2) cout<<"YES\n";
    else cout<<"NO\n";
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

