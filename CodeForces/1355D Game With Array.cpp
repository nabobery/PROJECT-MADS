#include <iostream>
using namespace std;

#pragma GCC optimize("Ofast")

void solve(){
    int n,s;
    cin >> n >> s;
    // for S >= 2*n, we can generate any subarray and show that Petya will always win
    // in this case, we take [2,2,.... s -2*(n-1)] and show that it's not possible for vasya to win as petya can choose 1 (and each subsegment has sum greater than 1)
    if(s >= 2*n){
        cout<<"YES\n";
        for(int i = 0; i < n-1;i++) cout<<"2 ";
        cout<<(s - 2*(n-1))<<"\n";
        cout<<"1\n";
    }
    // else when s < 2*n, petya will always lose
    else cout<<"NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}

