#include <iostream>
#include <vector>
#include <utility>
using namespace  std;

bool isSorted(int arr[], int n){
    for(int i = 1; i < n;i++){
        if(arr[i] >= arr[i-1]) continue;
        else return false;
    }
    return true;
}

void solve(){
    int n;
    cin >> n;
    int a[n], b[n];
    for(int i = 0; i < n;i++) cin >> a[i];
    for(int i = 0; i < n;i++) cin >> b[i];
    vector<pair<int,int>> swaps;
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if ((a[j] > a[j + 1] && b[j] >= b[j+1]) || (b[j] > b[j + 1] && a[j] >= a[j+1])){
                swap(a[j], a[j + 1]);
                swap(b[j], b[j + 1]);
                swaps.push_back({j,j+1});
            }
        }
    }
    if(isSorted(a,n) && isSorted(b,n)){
        cout<<swaps.size()<<"\n";
        for(auto it : swaps)
            cout<< it.first + 1<<" "<<it.second + 1<<"\n";
    }
    else cout<<"-1\n";
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


