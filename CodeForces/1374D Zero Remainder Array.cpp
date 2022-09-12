#include <iostream>
#include <map>
using namespace std;

// we know that we require at every iteration/cycle we can get only one remainder k - x%k
// therefore the min would be the remainder that has the highest frequency
// the number of moves = k*(frequency - 1)  (frequency -1 rounds) + remainder + 1 (last round)
#pragma GCC optimize("Ofast")

void solve(){
    int n,k, x;
    long long int result = 0;
    cin >> n >> k;
    map<int,int> mp;
    for(int i = 0; i < n;i++){
        cin >> x;
        mp[x%k]++;
    }
    if(mp[0] == n) cout<<result<<"\n";
    else{
        mp.erase(0);
        int max = mp.begin()->second, key = k - mp.begin()->first%k;
        for(auto itr : mp){
            if(itr.second > max){
                max = itr.second;
                key = k - itr.first%k;
            }
        }
        result = k;
        result *= (max - 1);
        result += (key + 1);
        cout<<result<<"\n";
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




