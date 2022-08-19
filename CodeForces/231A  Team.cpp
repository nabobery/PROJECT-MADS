#include <iostream>
using namespace std;

void solve(){
    int n,x,count, result = 0;
    cin >> n;
    for(int i = 0; i < n;i++){
        count = 0;
        for(int j = 0; j < 3;j++){
            cin >> x;
            if(x == 1) count++;
        }
        if(count >= 2) result++;
    }
    cout<<result<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

