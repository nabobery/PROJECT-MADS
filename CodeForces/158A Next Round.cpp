#include <iostream>
using namespace std;

#pragma GCC optimize("Ofast")

void solve(){
    int n, x,k, result = 0;
    cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n;i++) cin >> arr[i];
    x = arr[k-1];
    for(int i = 0; i < n;i++){
        if(arr[i] == 0) break;
        if(arr[i] >= x) result++;
        else break;
    }
    cout<<result<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}

