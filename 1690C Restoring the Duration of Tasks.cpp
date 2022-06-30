#include <iostream>
using namespace std;

void solve(){
    int n;
    cin >> n;
    int s[n], d[n];
    for(int i = 0; i < n;i++) cin >> s[i];
    for(int i = 0; i < n;i++) cin >> d[i];
    for(int i = 0; i < n;i++){
        if(i == 0) cout<<d[i] - s[i] <<" ";
        else{
            int result = s[i] < d[i-1] ? d[i] - d[i-1] : d[i] - s[i];
            cout<<result<<" ";
        }
    }
    cout<<"\n";
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





