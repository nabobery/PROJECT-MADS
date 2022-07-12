#include <iostream>
using namespace std;

void solve(){
    int n, k, count = 1;
    cin >> n >> k;
    long long int result = 0;
    int arr[n];
    for(int i = 0; i < n;i++) cin >> arr[i];
    for(int i = 0; i < n-1;i++){
        int div = (double)arr[i]/arr[i+1];
        if(div < 2) count++;
        else{
            if(count >= k+1){
                result += (count - k);
            }
            count = 1;
        }
    }
    if(count >= k+1){
        result += (count - k);
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

