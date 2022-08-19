#include<iostream>
using namespace std;

void solve(){
    int n,bi,t0 = 0,t1 = 0;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n;i++) cin >> arr[i];
    for(int i = 0; i < n;i++){
        cin >> bi;
        if(bi == 0) t0++;
        else t1++;
    }
    bool flag = false;
    for(int i = 1; i < n;i++){
        if(arr[i] >= arr[i-1]) continue;
        else{
            flag = true;
            break;
        }
    }
    if(!flag) cout<<"Yes\n";
    else{
        if(t0 >= 1 && t1 >= 1) cout<<"Yes\n";
        else cout<<"No\n";
    }
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

