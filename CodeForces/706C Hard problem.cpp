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
 
bool compare(string a, string b){
    for (int i = 0; i < min(a.size(), b.size()); i++)
    {
        if (a[i] < b[i])
            return true;
        if (a[i] > b[i])
            return false;
    }
    return a.size() <= b.size();
}
 
void solve(){
    int n;
    cin >> n;
    int c[n];
    string s[n], r1, r2;
    for(int i = 0; i < n;i++) cin >> c[i];
    for(int i = 0; i < n;i++) cin >> s[i];
    ll dp = 0, dp_rev = c[0], curr, curr_rev;
    r1 = s[0];
    reverse(r1.begin(), r1.end());
    for(int i = 1; i < n;i++){
        curr = curr_rev = 1e14;
        r2 = s[i];
        reverse(r2.begin(), r2.end());
        // no reverse of s[i] required case
        if(compare(s[i-1], s[i])) curr = min(dp, curr);
        if(compare(r1, s[i])) curr = min(dp_rev, curr);
        // reverse of s[i] required case
        if(compare(s[i-1], r2)) curr_rev = min(curr_rev, dp + c[i]);
        if(compare(r1, r2)) curr_rev = min(curr_rev, dp_rev + c[i]);
        r1 = r2;
        dp = curr;
        dp_rev = curr_rev;
    }
    if(dp == 1e14 && dp_rev == 1e14){
        cout<<"-1\n";
        return;
    }
    cout<<min(dp, dp_rev)<<"\n";
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