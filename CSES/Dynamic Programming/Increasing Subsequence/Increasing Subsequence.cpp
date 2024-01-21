#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#pragma GCC optimize("Ofast")

// DP Solution using Binary Search (Rewriting the LIS to generate better ones)
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
void solve(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n;i++) cin >> arr[i];
    vector<int> dp;
    for(auto x : arr){
        auto it = lower_bound(dp.begin(), dp.end(),x);
        if(it == dp.end()) dp.push_back(x);
        else *it = x;
    }
    cout<<dp.size()<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}

