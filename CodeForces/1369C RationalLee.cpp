#include <iostream>
#include <algorithm>
using namespace std;

#pragma GCC optimize("Ofast")

void solve(){
    int n,k;
    cin >> n >> k;
    int a[n], w[k];
    for(int i = 0; i < n;i++) cin >> a[i];
    for(int i = 0; i < k;i++) cin >> w[i];
    // sort a in non-decreasing order
    sort(a, a + n);
    // sort w for now in non-descending order
    sort(w, w + k);
    int l = 0, r = n-1, p = 0;
    long long int result = 0;
    // to get max happiness when w = 1 such that sum is max is to take the largest elements by moving the r pointer by 1
    while (p < k){
        if(w[p] == 1){
            result += (2*a[r]);
            r--;
            p++;
        }
        else break;
    }
    // now sort w in non-increasing order such that we maximise our sum by moving the l pointer more and getting larger minimum as we iterate
    sort(w + p, w + k, greater<int>());
    while(p < k){
        // add the largest element done till now and minimum element
        result += (a[l] + a[r]);
        // move the l pointer by wi - 1
        l += (w[p] - 1);
        // r pointer by 1
        r--;
        p++;
    }
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

