#include <iostream>
using namespace  std;

int a[100];

void solve(){
    int n;
    long long int h;
    cin >> n >> h;
    for(int i = 0; i < n;i++){
        cin >> a[i];
    }
    int diff[n-1];
    for(int i = 1; i < n; i++) diff[i-1] = a[i] - a[i-1];
    long long int l = 1, r = 1e18, mid,result;
    while(l <= r){
        mid = (l + r) / 2;
        long long int sum = mid;
        for(int i = 0; i < n-1;i++){
            if(diff[i] < mid) sum += diff[i];
            else sum += mid;
        }
        if(sum >= h){
            result = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
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



