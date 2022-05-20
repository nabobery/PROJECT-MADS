#include <iostream>
#include <algorithm>
#include <functional>
using namespace  std;

void solve(){
    int n;
    cin >> n;
    bool exists[n+1];
    int arr[n];
    for(int i = 0; i <= n;i++) exists[i] = false;
    for(int i = 0; i < n;i++) cin >> arr[i];
    sort(arr, arr + n, greater<int>());
    bool flag = false;
    for(int i = 0; i < n;i++){
        int curr = arr[i];
        while(curr > n || exists[curr]){
            curr /= 2;
        }
        if(curr > 0) exists[curr] = true;
        else{
            flag = true;
            break;
        }
    }
    if(!flag) cout<<"YES\n";
    else cout<<"NO\n";
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


