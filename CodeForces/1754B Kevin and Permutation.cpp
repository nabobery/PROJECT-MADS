#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#pragma GCC optimize("Ofast")

#define ll long long int

void solve(){
    int n;
    cin >> n;
    if(n % 2){
        int temp = n-1;
        for(int i = 0; i < temp/2; i++){
            cout<<temp/2-i<<" "<<temp - i<<" ";
        }
        cout<<n<<"\n";
    }
    else{
        for(int i = 0; i < n/2; i++){
            cout<<n/2-i<<" "<<n - i<<" ";
        }
        cout<<"\n";
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

