#include <iostream>
#include <algorithm>
using namespace  std;

int arr[200000];

void solve(){
    int n;
    cin >> n;
    for(int i = 0; i < n;i++) cin >> arr[i];
    int l = -1, r = -1;
    for(int i = 0; i < n - 1;i++){
        if(arr[i] == arr[i+1]){
            l = i;
            break;
        }
    }
    for(int i = n-1; i > 0;i--){
        if(arr[i] == arr[i-1]){
            r = i-1;
            break;
        }
    }
    if(l == r) cout<<"0\n";
    else cout<<max(r-l-1,1)<<"\n";
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

