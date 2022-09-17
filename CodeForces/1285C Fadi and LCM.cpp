#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

#pragma GCC optimize("Ofast")

#define ll long long int

bool comparator(pair<ll,ll> &a, pair<ll,ll> &b){
    return max(a.first,a.second) < max(b.first, b.second);
}

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

void solve(){
    ll x, a,b;
    cin >> x;
    vector<pair<ll,ll>> vec;
    for (ll i = 1;i <= (ll)sqrt(x); i++) {
        if(x % i == 0){
            if(gcd(x/i,i) == 1){
                a = x/i;
                b = i;
                vec.push_back({a,b});
            }
        }
    }
    sort(vec.begin(),vec.end(), comparator);
    cout<<vec[0].first<<" "<<vec[0].second<<"\n";
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


