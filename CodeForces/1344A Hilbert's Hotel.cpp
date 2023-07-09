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
    int n, x;
    cin >> n;
    vector<int> count(n,0);
    for(int i = 0; i < n;i++){
        cin >> x;
        count[((x+i)%n + n)%n]++;
 
    }
    bool flag = true;
    for(int i = 0; i < n;i++){
        if(count[i] > 1){
            flag = false;
            break;
        }
    }
    cout<<(flag ? "YES\n" : "NO\n");
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