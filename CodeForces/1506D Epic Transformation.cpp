#include <iostream>
#include <map>
using namespace std;

#pragma GCC optimize("Ofast")

void solve(){
    int n,x,max = 0;
    cin >> n;
    map<int,int> mp;
    for(int i = 0; i < n;i++){
        cin >> x;
        mp[x]++;
    }
    for(auto itr : mp){
        if(itr.second > max) max = itr.second;
    }
    if((2*max - n) <= 0){
        if(n%2) cout<<"1\n";
        else cout<<"0\n";
    }
    else cout<<(2*max - n)<<"\n";
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

