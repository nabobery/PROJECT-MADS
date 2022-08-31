#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

void solve(){
    int n,l;
    cin >> n >> l;
    int arr[n];
    double  diff,result = 0;
    for(int i = 0; i < n;i++) cin >> arr[i];
    sort(arr,arr+n);
    if(arr[0] > result) result = arr[0];
    if(l - arr[n-1] > result) result = (l - arr[n-1]);
    result *= 2;
    for(int i = 1; i < n;i++){
        diff = arr[i] - arr[i-1];
        if(diff > result) result = diff;
    }
    cout << fixed << setprecision(9) <<result/2<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}



