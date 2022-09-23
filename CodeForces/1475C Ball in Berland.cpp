#include <iostream>
#include <map>
using namespace std;

#pragma GCC optimize("Ofast")

#define  ll long long int

void solve(){
    int a,b,k;
    ll result = 0;
    cin >> a >> b >> k;
    map<int,int> mp1, mp2;
    int boys[k], girls[k];
    for(int i = 0; i < k;i++){
        cin >> boys[i];
        mp1[boys[i]]++;
    }
    for(int i = 0; i < k;i++){
        cin >> girls[i];
        mp2[girls[i]]++;
    }
    // fix bi and gi and find all pairs possible for the 2nd pair
    for(int i = 0; i < k;i++){
        int temp = (k - mp1[boys[i]] - mp2[girls[i]] + 1);
        result += temp;
    }
    // divide by 2 to remove duplicates
    cout<<result/2<<"\n";
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


