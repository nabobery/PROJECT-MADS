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
    int n;
    ll result = 0;
    cin >> n;
    int a[n];
    for(int i = 0; i < n;i++){
        cin >> a[i];
        if(i%2 == 0) result += a[i];
    }
    ll max_so_far = 0, max_ending_here = 0;
    for (int i = 0; i < n/2; i++) {
        max_ending_here = max_ending_here + (a[2*i +1] - a[2*i]);
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
 
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    max_ending_here = 0;
    for (int i = 1; i < n-1; i+=2) {
        max_ending_here = max_ending_here + (a[i] - a[i+1]);
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
 
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    cout<<result+max_so_far<<"\n";
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