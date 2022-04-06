#include <iostream>
using namespace  std;

void solve(int n){
    int arr[n], max  = 0, max_index = 0;
    for(int i = 0; i < n;i++){
        cin >> arr[i];
        if(arr[i] > max){
            max = arr[i];
            max_index = i;
        }
    }
    if(n == 1){
        if(arr[0] == 1) cout<<"YES\n";
        else cout<<"NO\n";
        return;
    }
    else{
        for(int i = 0; i < n;i++){
            if(arr[i] == max - 1) {
                cout << "YES\n";
                return;
            }
            else if(arr[i] == max && max_index != i){
                cout << "YES\n";
                return;
            }
        }
    }
    cout<<"NO\n";
}

int main() {
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        solve(n);
    }
    return 0;
}
