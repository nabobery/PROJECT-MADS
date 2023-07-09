#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;
 
#pragma GCC optimize("Ofast")
 
#define ll long long int
 
void solve(){
    int n,m;
    cin >> n >> m;
    int a[n], b[m];
    for(int i = 0; i < n;i++) cin >> a[i];
    for(int i = 0; i < m;i++) cin >> b[i];
    for(int k = 0; k < 512;k++){
        bool f = true;
        for(int i = 0; i < n;i++){
            bool flag = false;
            for(int j = 0; j < m;j++){
                if(((a[i] & b[j]) | k) == k){
                    flag = true;
                    break;
                }
            }
            f &= flag;
            if(!flag) break;
        }
        if(f){
            cout<<k<<"\n";
            return;
        }
    }
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