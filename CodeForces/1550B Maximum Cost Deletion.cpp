#include <iostream>
using namespace  std;

void solve(){
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    if(b >= 0){
        cout<<n*(a+b)<<"\n";
    }
    else{
        int m = 0; // number of operations (should be min as b < 0)
        char ch = s[0];
        for(int i = 1; i < n;i++){
            if(ch == s[i]) continue;
            else{
                ch = s[i];
                m++;
            }
        }
        m++;
        cout<<n*a + (m/2 + 1)*b<<"\n";
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

