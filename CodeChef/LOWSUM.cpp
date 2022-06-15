#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

void solve() {
    int k, q;
    cin >> k >> q;
    vector<long long> A(k), B(k), ans;
    for (int i = 0; i < k; i++) {
        cin >> A[i];
    }
    for(int i = 0; i < k; i++) {
        cin >> B[i];
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    for (int i = 0; i < min(k, 10000); i++) {
        for (int j = 0; j < min(k, (int) ceil(10000.0 / (i + 1.0))); j++) {
            ans.push_back(A[i] + B[j]);
        }
    }
    sort(ans.begin(),ans.end());
    int x;
    while (q--) {
        cin >> x;
        cout << ans[x - 1] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
