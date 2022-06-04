#include <iostream>
using namespace  std;

void solve(){
    long long int n, k;
    cin >> n >> k;
    if(k == 1){
        cout<<n-1<<"\n";
    }
    else{
        long long int result = 0, temp = 1, i = 1;
        while(temp < n && i <= k){
            temp += i;
            result++;
            if(temp >= k) break;
            else i = temp;
        }
        result += (n - temp)/k;
        if((n-temp) % k > 0) result++;
        cout<<result<<"\n";
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

