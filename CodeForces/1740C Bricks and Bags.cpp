#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#pragma GCC optimize("Ofast")

#define ll long long int

void solve(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n;i++) cin >> arr[i];
    sort(arr, arr + n);
    ll result = 0;
    for(int i = n-1; i > 1;i--){
        ll temp = 2*arr[i];
        temp -= (arr[i-1] + arr[0]);
        result = max(result,temp);
    }
    for(int i = 0; i < n-2;i++){
        ll temp = (arr[n-1] + arr[i+1]);
        temp -= 2*arr[i];
        result = max(result,temp);
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