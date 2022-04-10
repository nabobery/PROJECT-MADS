#include <iostream>
#include<cmath>
using namespace  std;

int limit = (log2(1000000000)/log2(3)) + 1;

void solve(){
    int n;
    cin >> n;
    if(n > limit){
        cout<<"NO\n";
    }
    else{
        cout<<"YES\n";
        int result = 1;
        cout<<result<<" ";
        for(int i = 2; i <= n; i++){
            result *= 3;
            cout<<result<<" ";
        }
        cout<<"\n";
    }
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}


