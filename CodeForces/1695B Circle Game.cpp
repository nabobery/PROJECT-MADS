#include <iostream>
using namespace std;

void solve(){
    int n, least = 1e9 + 1,x;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n;i++){
        cin >> arr[i];
        if(arr[i] < least){
            least = arr[i];
        }
    }
    if(n % 2){
        cout<<"Mike\n";
    }
    else{
        for(int i = 0; i < n;i++){
            if(least == arr[i]){
                x = i;
                break;
            }
        }
        if(x%2) cout<<"Mike\n";
        else cout<<"Joe\n";
    }
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




