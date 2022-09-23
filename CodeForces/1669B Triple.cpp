#include <iostream>
#include <map>
using namespace std;

#pragma GCC optimize("Ofast")

void solve(){
    // using the fact max ai is 2*10^5
    int n,x, l = 1e9;
    cin >> n;
    map<int,int> mp;
    mp[l] = 3;
    for(int i = 0; i < n;i++){
        cin >> x;
        mp[x]++;
    }
    bool flag = true;
    for(auto itr : mp){
        if(itr.second >= 3){
            if(itr.first != l) cout<<itr.first<<"\n";
            else cout<<"-1\n";
            break;
        }
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


