#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#pragma GCC optimize("Ofast")

#define ll long long int

// the logic is to pair the largest element with largest number of times it occurs in the queries
void solve(){
    int n,q,l,r;
    cin >> n >> q;
    int arr[n];
    for(int i = 0; i < n;i++) cin >> arr[i];
    sort(arr, arr +n);
    vector<int> d(n+1,0),b(n);
    // simulate the number of times an element occurs by increasing d[l] and decrementing d[r+1]
    for(int i = 0; i < q;i++){
        cin >> l >> r;
        d[l-1]++;
        d[r]--;
    }
    b[0] = d[0];
    for(int i = 1; i < n;i++){
        b[i] = d[i] + b[i-1];
    }
    sort(b.begin(),b.end());
    ll result = 0;
    // get the result by pairing the element with how many times it occurs => a[i]<= a[j] and b[i] <= b[j]
    for(int i = 0; i < n;i++){
        ll temp = arr[i];
        temp *= b[i];
        result += temp;
    }
    cout<<result<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}


