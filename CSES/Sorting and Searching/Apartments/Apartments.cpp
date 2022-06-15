#include <iostream>
#include <algorithm>
using namespace  std;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    int a[n], b[m];
    for(int i = 0; i < n;i++) cin >> a[i];
    for(int i = 0; i < m;i++) cin >> b[i];
    sort(a,a +n);
    sort(b,b + m);
    int result = 0;
    int j  = 0;
    for(int i = 0; i < m;i++){
        int curr = b[i];
        if(j > n) break;
        if(a[j] - k > curr) continue;
        else if(a[j] - k <= curr && curr <= a[j] + k) {
            result++;
            j++;
            continue;
        }
        else {
            while(a[j] + k < curr && j < n){
                j++;
            }
            if(j < n && a[j] - k <= curr && curr <= a[j] + k){
                result++;
                j++;
            }
        }
    }
    cout<<result<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}

