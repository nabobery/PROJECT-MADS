#include <iostream>
using namespace  std;

void solve(){
    int n, m, max_a = 0, max_b = 0;
    cin >> n;
    int a[n];
    for(int i = 0; i < n;i++){
        cin >> a[i];
        if(a[i] > max_a) max_a = a[i];
    }
    cin >> m;
    int b[m];
    for(int i = 0; i < m;i++){
        cin >> b[i];
        if(b[i] > max_b) max_b = b[i];
    }
    if(max_a > max_b){
        cout<<"Alice\nAlice\n";
    }
    else if(max_b > max_a){
        cout<<"Bob\nBob\n";
    }
    else if(max_a == max_b){
        cout<<"Alice\n";
        cout<<"Bob\n";
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




