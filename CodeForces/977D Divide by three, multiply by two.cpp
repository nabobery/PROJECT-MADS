#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#pragma GCC optimize("Ofast")

#define ll long long int

int count(ll x){
    int result = 0;
    while(x % 3 == 0){
        result++;
        x /= 3;
    }
    return result;
}

void solve(){
    int n;
    ll x;
    cin >> n;
    vector<pair<int,ll>> vec(n);
    for(int i = 0; i < n;i++){
        cin >> vec[i].second;
        vec[i].first = -count(vec[i].second);
    }
    // sorting in the decreasing order of count (x/3) and if count is same it's in increasing order of values (2*x)
    sort(vec.begin(),vec.end());
    for(auto itr : vec) cout<<itr.second<<" ";
    cout<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}


