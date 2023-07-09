#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
 
#pragma GCC optimize("Ofast")
 
#define ll long long int
 
void solve(){
    int n;
    cin >> n;
    if(n == 1){
        int x;
        cin >> x;
        cout<<"1 1\n 0\n1 1\n 0\n1 1\n";
        cout<<-x<<"\n";
 
    }
    else{
        ll a[n];
        for(int i = 0; i < n;i++) cin >> a[i];
        cout<<1<<" "<<n<<"\n";
        for(int i = 0; i < n; i++) cout<<(n - a[i]% (n-1) - 1)*n<<" ";
        cout<<"\n";
        for(int i = 0; i < n;i++) a[i] += (n - a[i]% (n-1) - 1)*n;
        cout<<1<<" "<<n-1<<"\n";
        for(int i = 0; i < n-1;i++) cout << -a[i]<<" ";
        cout<<"\n";
        cout<<n<<" "<<n<<"\n";
        cout<<-a[n-1]<<"\n";
    }
}
 
 
int main() {
    ios_base::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}