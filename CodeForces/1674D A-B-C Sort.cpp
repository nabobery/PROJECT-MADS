#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> unsorted(n);
    for(int i = 0; i < n;i++) cin >> arr[i];
    unsorted = arr;
    bool flag = false;
    sort(arr.begin(),arr.end());
    for(int i = n-1; i > 0;i-= 2){
        if(unsorted[i-1] > unsorted[i]) swap(unsorted[i],unsorted[i-1]);
    }
    for(int i = 0; i < n;i++){
        if(arr[i] != unsorted[i]){
            flag = true;
            break;
        }
    }
    if(flag) cout<<"NO\n";
    else cout<<"YES\n";

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


