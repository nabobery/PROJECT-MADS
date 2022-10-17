#include <iostream>
#include <cmath>
using namespace std;

#pragma GCC optimize("Ofast")

void solve(){
    int k;
    cin >> k;
    int temp = floor(sqrt(k));
    int diff = k - pow(temp,2);
    if(temp*temp == k) cout<<temp<<" "<<1<<"\n";
    else{
        if(diff <= temp+1){
            cout<<diff<<" "<<temp+1<<"\n";
        }
        else{
            cout<<temp+1<<" "<<(2*(temp+1) - diff)<<"\n";
        }
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




