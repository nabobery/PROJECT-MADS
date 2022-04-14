#include <iostream>
#include <cstdlib>
using namespace  std;

void solve(){
    int n;
    cin >> n;
    int a[n], b[n];
    for(int i = 0; i < n;i++){
        cin >> a[i];
    }
    for(int j = 0; j < n;j++){
        cin >> b[j];
    }
    for(int i = 0; i < n;i++){
        if(a[i] > b[i]){
            int temp = b[i];
            b[i] = a[i];
            a[i] = temp;
        }
    }
    long long int sum = 0;
    for(int i = 0; i < n - 1;i++){
        sum += abs(a[i]- a[i+1]);
        sum += abs(b[i]- b[i+1]);
    }
    cout<<sum<<"\n";
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}


