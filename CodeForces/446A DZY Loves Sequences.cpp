#include <iostream>
#include <vector>
#include <unordered_map>
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
    int n, start = 0, end = 0,result = 0, prevstart = -1, prevend = 0;
    cin >> n;
    int a[n+1];
    for(int i = 0; i < n;i++) cin >> a[i];
    a[n] = -1;
    for(int i = 1; i <= n;i++){
        if(a[i] <= a[i-1]){
            end = i-1;
            result = max(end-start+2, result);
            if(prevstart != -1){
                if((start-prevend == 1 && (a[start+1] - a[prevend] > 1 || a[start] - a[prevend-1] > 1)) || (start- prevend == 2 && a[start] - a[prevend] > 1)){
                    result = max(result, end - prevstart + 1);
                }
            }
            prevstart = start;
            prevend = end;
            start = i;
        }
    }
    if(result > n) result = n;
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