#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

#pragma GCC optimize("Ofast")

#define ll long long int

void solve(){
    int n,m,d;
    cin >> n >> m >> d;
    ll result = 0;
    int arr[n*m];
    for(int i = 0; i < n*m;i++){
        cin >> arr[i];
    }
    sort(arr, arr+ n*m);
    int median = arr[(n*m)/2];
    bool flag = true;
    for(int i = 0; i < n*m;i++){
        if(abs(median - arr[i])%d == 0){
            result += abs(median - arr[i])/d;
        }
        else{
            flag = false;
            break;
        }
    }
    if(!flag) cout<<"-1\n";
    else cout<<result<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}




