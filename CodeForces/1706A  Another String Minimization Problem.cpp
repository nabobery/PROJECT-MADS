#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(){
    int n, m,x;
    cin >> n >> m;
    vector<bool> arr(m+1,false);
    for(int i = 0; i < n;i++){
        cin >> x;
        int y = m+1 - x;
        if(!arr[min(x,y)]) arr[min(x,y)] = true;
        else arr[max(x,y)] = true;
    }
    for(int i = 1; i <= m;i++){
        cout<<(arr[i] ? "A" : "B");
    }
    cout<<"\n";
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

