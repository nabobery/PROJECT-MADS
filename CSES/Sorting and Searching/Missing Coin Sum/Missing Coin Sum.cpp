#include <iostream>
#include <algorithm>
using namespace std;

void solve(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n;i++) cin >> arr[i];
    sort(arr, arr+n);
    long long int result = 1;
    for(int i = 0; i < n && arr[i] <= result;i++){
        result += arr[i];
    }
    cout<<result<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}

