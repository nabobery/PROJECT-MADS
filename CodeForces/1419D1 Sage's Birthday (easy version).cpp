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
    if(n < 3){
        cout<<"0\n";
        for(auto i : arr) cout<<i<<" ";
        cout<<"\n";
        return;
    }
    sort(arr, arr + n);
    cout<<(n-1)/2<<"\n";
    for(int i = 0; i < n/2;i++){
        cout<<arr[n/2 + i]<<" "<<arr[i]<<" ";
    }
    if(n % 2) cout<<arr[n-1];
    cout<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}






