#include <iostream>
#include <algorithm>
using namespace std;

void solve(){
    int n,t,result = 0,x;
    cin >> n >> t;
    int l = 0;
    int prefixSum[n+1];
    prefixSum[0] = 0;
    for(int i = 0; i < n;i++){
        cin >> x;
        prefixSum[i+1] = prefixSum[i] + x;
    }
    for(int r = 1; r <= n;r++){
        if(prefixSum[r] - prefixSum[l] <= t){
            result = max(result, r-l);
        }
        else{
            l++;
            if(prefixSum[r] - prefixSum[l] <= t){
                result = max(result, r-l);
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




