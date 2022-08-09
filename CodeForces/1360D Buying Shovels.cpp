#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

bool isPrime(int n){
    if(n == 1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void solve(){
    int n,k;
    cin >> n >> k;
    if(n <= k) cout<<"1\n";
    else if(isPrime(n)) cout<<n<<"\n";
    else{
        int result = 1e9 + 1;
        for(int i = 1; i <= sqrt(n);i++){
            if(i > k) break;
            if(n % i == 0){
                result = min(n/i,result);
                int temp = n/i;
                if(temp <= k) result = min(n/temp, result);
            }
        }
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


