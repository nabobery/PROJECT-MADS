#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

#define ll long long int

void solve(){
    int n,a,b,x;
    cin >> n >> a >> b;
    ll result = -1e18,sum = 0;
    vector<ll> prefixSum;
    // an array of prefixsums
    prefixSum.push_back(sum);
    for(int i = 0; i < n;i++){
        cin >> x;
        sum += x;
        prefixSum.push_back(sum);
    }
    // a set to maintain prefisums of subarrays between length a and b
    multiset<ll> s;
    // we maintain a window of b and then find the max subarray sum and continue
    for(int i = a; i <= n;i++){
        // if size > b erase the start element's prefixSum of this window
        if(i > b) s.erase(s.find(prefixSum[i-b-1]));
        // insert the last element's prefixsum of the current window
        s.insert(prefixSum[i-a]);
        // get the maximum subarray sum possible
        result = max(result, prefixSum[i] - *s.begin());
    }
    cout<<result<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}


