#include <iostream>
using namespace std;

void solve(){
    int n,x,sum = 0;
    cin >> n;
    int prefixSum[n];
    for(int i = 0; i < n;i++){
        cin >> x;
        sum += x;
        prefixSum[i] = sum;
    }
    int result = 0, l = 0, r = n-1;
    while(l < r){
        if(prefixSum[l] == (prefixSum[n-1] - prefixSum[r-1])){
            int temp = l + (n-r) + 1;
            if(temp > result) result = temp;
            l++;
            r--;
        }
        else if(prefixSum[l] > (prefixSum[n-1] - prefixSum[r-1])) r--;
        else l++;
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




