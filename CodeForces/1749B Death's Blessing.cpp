#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#pragma GCC optimize("Ofast")

#define ll long long int

void solve(){
    int n,x;
    cin >> n;
    int b[n];
    long long int result = 0;
    for(int i = 0; i < n;i++){
        cin >> x;
        result += x;
    }
    for(int i = 0; i < n;i++) cin >> b[i];
    if(n == 1){
        cout<<result<<"\n";
    }
    else{
        int l = 0, r = n-1, temp = 0;
        while(l <= r){
            result += temp;
            if(b[l] > b[r]){
                temp = b[r];
                r--;
            }
            else{
                temp = b[l];
                l++;
            }
        }
        cout<<result<<"\n";
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


