#include <iostream>
#include <algorithm>
using namespace std;

void solve(){
    int n,k;
    cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n;i++) cin >> arr[i];
    long long int result = 0;
    sort(arr, arr +n);
    // get the sum of first n-2k numbers in ascending order to get the least sum => score
    for(int i = 0; i < n - 2*k;i++) result += arr[i];
    // then use the greatest 2*k elements as fractions so that we can minimise the score
    for(int i = n - 2*k; i < n - k;i++){
        result += (arr[i]/arr[k+i]);
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

