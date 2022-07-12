#include <iostream>
using namespace std;

void solve(){
    int a,x,result = 0;
    cin >> a;
    for(int i = 0; i < 3;i++){
        cin >>x;
        if(x > a) result++;
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

