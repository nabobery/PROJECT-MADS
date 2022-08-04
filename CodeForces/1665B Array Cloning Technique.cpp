#include <iostream>
#include <map>
#include <cmath>
using namespace std;

void solve(){
    int max = 0, n, x;
    cin >> n;
    map<int,int> mp;
    for(int i = 0; i < n;i++){
        cin >> x;
        mp[x]++;
        if(mp[x] > max) max = mp[x];
    }
    // number of swaps
    long long int result = (n - max);
    // number of clones
    result += ceil(log2((double)n/max));
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



