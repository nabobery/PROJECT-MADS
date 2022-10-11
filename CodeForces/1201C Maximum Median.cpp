#include <iostream>
#include <algorithm>
using namespace std;

#pragma GCC optimize("Ofast")

void solve(){
    int n,k,cost;
    cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n;i++) cin >> arr[i];
    if(n == 1){
        arr[0] += k;
        cout<<arr[0]<<"\n";
    }
    else{
        sort(arr, arr + n);
        while(true){
            int upper = upper_bound(arr, arr+n, arr[n/2]) - arr;
            if(upper == n){
                arr[n-1] += (k/(n/2 + 1));
                upper--;
                cost = n/2+1;
            }
            else cost = (upper - n/2);
            if(k - cost >= 0){
                int temp = k/cost;
                if(temp > (arr[upper] - arr[n/2])) temp = arr[upper] - arr[n/2];
                for(int i = n/2; i < upper;i++){
                    arr[i] += temp;
                }
                k -= (temp*cost);
            }
            else break;
        }
        cout<<arr[n/2]<<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}




