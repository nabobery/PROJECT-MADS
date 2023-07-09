#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;
 
#pragma GCC optimize("Ofast")
 
#define ll long long int
 
void solve(){
    int n,k;
    cin >> n >> k;
    for(int i = 0; i < k-3;i++){
        cout<<"1 ";
    }
    n = n-k+3;
    if(n%2) cout<<n/2<<" "<<n/2<<" 1\n";
    else{
        if(n%4) cout<<(n-2)/2<<" "<<(n-2)/2<<" 2\n";
        else cout<<n/2<<" "<<n/4<<" "<<n/4<<"\n";
    }
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