#include <iostream>
using namespace  std;

bool check(int arr[], int n){
    for(int i = 1; i < n;i++){
        if(arr[i-1] >= arr[i]) return false;
    }
    return true;
}

void solve(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n;i++) cin >> a[i];
    int result = 0;
    if(n == 1) cout<<result<<"\n";
    else {
        for (int i = n - 1; i > 0; i--) {
            if (a[i] > a[i - 1]) continue;
            else {
                while (a[i - 1] != 0 && a[i - 1] >= a[i]) {
                    a[i - 1] /= 2;
                    result++;
                }
                if (a[i - 1] >= a[i]) break;
            }
        }
        if (!check(a, n)) cout << "-1\n";
        else cout << result << "\n";
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


