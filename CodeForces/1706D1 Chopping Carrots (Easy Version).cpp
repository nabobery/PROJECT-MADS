#include <iostream>
#include <algorithm>
using namespace std;

void solve(){
    int n, k, pi,curr_max;
    cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n;i++) cin >> arr[i];
    int result = (arr[n-1]/k - arr[0]/k);
    for(int v = 1; v <= arr[0];v++){
        curr_max = 0;
        for(int i = 0; i < n;i++){
            pi = min(k, arr[i]/v);
            curr_max = max(curr_max, arr[i]/pi);
        }
        result = min(result, curr_max - v);
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



