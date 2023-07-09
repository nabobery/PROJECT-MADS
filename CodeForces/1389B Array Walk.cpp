#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
 
#pragma GCC optimize("Ofast")
 
#define ll long long int
 
void solve(){
    int n,k,z;
    cin >> n >> k >> z;
    int a[n];
    for(int i = 0; i < n;i++) cin >> a[i];
    int result = 0;
    for(int i = 0; i <= z;i++){
        int temp = 0, ma = 0;
        if(k < 2*i) break;
        for(int j = 0; j < k - 2*i + 1;j++){
            ma = max(ma, a[j] + a[j+1]);
            temp += a[j];
        }
        temp += i*ma;
        result = max(result,temp);
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