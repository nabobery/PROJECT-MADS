#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#pragma GCC optimize("Ofast")

#define ll long long int

void solve(){
    int n;
    cin >> n;
    int p[n];
    for(int i = 0; i < n;i++) cin >> p[i];
    for(int i = 0; i < n;i++){
        int pos = p[i]-1;
        int res = 1;
        while(pos != i){
            res++;
            pos = p[pos]-1;
        }
        cout<<res<<" ";
    }
    cout<<"\n";
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






