#include <iostream>
using namespace std;

void solve(){
    int n,k;
    cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n;i++) cin >> arr[i];
    if(k >= 2){
        int count = 0;
        for(int i = 1; i < n-1;i++){
            if(arr[i] > (arr[i-1] + arr[i+1])) count++;
        }
        cout<<count<<"\n";
    }
    else cout<<(n-1)/2<<"\n";

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



