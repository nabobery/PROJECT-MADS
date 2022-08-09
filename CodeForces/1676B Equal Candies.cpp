#include <iostream>
using namespace std;

void solve(){
    int n, min = 1e7 + 1;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n;i++){
        cin >> arr[i];
        if(arr[i] < min) min = arr[i];
    }
    int result = 0;
    for(int i = 0; i < n;i++){
        result += (arr[i] - min);
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


