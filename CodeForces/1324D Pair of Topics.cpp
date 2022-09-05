#include <iostream>
#include <algorithm>
using namespace std;

void solve(){
    int n;
    cin >> n;
    int a[n],b[n],diff[n];
    for(int i = 0; i < n;i++) cin >> a[i];
    for(int i = 0; i < n;i++) cin >> b[i];
    // get difference b/w ai and bi
    for(int i = 0; i < n;i++) diff[i] = a[i] - b[i];
    // sort it
    sort(diff, diff + n);
    long long int result = 0;
    // diff_i + diff_j > 0 => diff_j >= -diff_i + 1
    for(int i = 0; i < n;i++){
        // if diff <= 0, skip because every j less than i will give diff_i + diff_j <= 0
        if(diff[i] <= 0) continue;
        // else calculate the lowerbound such that we get diff_j for diff_i such that diff_i + diff_j > 0
        int j = lower_bound(diff, diff + i, -diff[i] + 1) - diff;
        result += i - j;
    }
    cout<<result<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}




