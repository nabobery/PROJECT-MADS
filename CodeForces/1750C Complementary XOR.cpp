#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#pragma GCC optimize("Ofast")

#define ll long long int

void solve(){
    int n;
    string a,b;
    cin >> n >> a >> b;
    bool flag = true;
    for(int i = 0; i < n;i++){
        if(a[i] == b[i]){
            flag = false;
            break;
        }
    }
    flag = flag || (a == b);
    // if a != b and a != !b
    if(!flag){
        cout<<"NO\n";
    }
    else{
        vector<pair<int,int>> res;
        vector<int> counter(n,0);
        // if a = ~b we make it to a = b by doing the (1,n) operation
        if(a[0] != b[0]){
            res.push_back({1,n});
            a = b;
        }
        for(int i = 0; i < n;i++){
            // if ai = bi = 1 then do {1,i} and {1,i-1} to change ai and bi to 0, we maintain parity to reduce number of operations
            if(a[i] == '1'){
                if(i != 0){
                    counter[i]++;
                    counter[i-1]++;
                }
                // if a1 = b1 = 1 then do {1,n} and {2,n} to change a1 = b1 = 0
                else{
                    res.push_back({1,n});
                    res.push_back({2,n});
                }
            }
        }
        for(int i = 0; i < n;i++){
            // if parity is odd means we need to flip the ith bit, so we do {1,i} operation, the others don't need as they'll be zero after all these operations
            if(counter[i] % 2){
                res.push_back({1,i+1});
            }
        }
        cout<<"YES\n"<<res.size()<<"\n";
        for(auto itr : res){
            cout<<itr.first<<" "<<itr.second<<"\n";
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






