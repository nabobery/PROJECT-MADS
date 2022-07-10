#include <iostream>
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    long long int result = m*(m+1);
    result /= 2;
    long long int temp = n*(n+1);
    temp *= m;
    temp /= 2;
    result += temp;
    result -= m;
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



