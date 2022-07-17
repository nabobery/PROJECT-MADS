#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace  std;

void solve(){
    int n,median;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n;i++) cin >> arr[i];
    sort(arr,arr+n);
    if(n % 2 == 0)  median = (arr[n/2 - 1] + arr[n/2])/2;
    else median = arr[n/2];
    long long int result = 0;
    for(int i = 0; i < n;i++){
        result += abs(arr[i] - median);
    }
    cout<<result<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}

