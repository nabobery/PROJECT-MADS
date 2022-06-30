#include <iostream>
#include <cmath>
using namespace std;

int arr[31];

void updateArr(int n){
    int count = 0;
    while (n) {
        if(n & 1) arr[count]++;
        n >>= 1;
        count++;
    }
}

void solve(){
    int n, k,x;
    cin >> n >> k;
    for(int i = 0; i < 31;i++) arr[i] = 0;
    for(int i = 0; i < n;i++){
        cin >> x;
        updateArr(x);
    }
    for(int i = 30; i > -1;i--){
        int diff = n - arr[i];
        if(k > 0 && diff <= k){
            arr[i] = n;
            k -= diff;
        }
    }
    int result = 0;
    for(int i = 0; i < 31;i++){
        if(arr[i] == n) result += pow(2,i);
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





