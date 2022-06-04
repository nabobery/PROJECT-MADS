#include <iostream>
using namespace  std;

int arr[100000];

void solve(){
    int n, result = 0;
    cin >> n;
    for(int i = 0; i < n;i++) cin >> arr[i];
    for(int i = 0; i < n - 1;i++){
        if(arr[i] < arr[i+1]) continue;
        else{
            result++;
            if(i + 2 < n) i++;
        }
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

