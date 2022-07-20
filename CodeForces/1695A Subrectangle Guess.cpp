#include <iostream>
#include <algorithm>
using namespace std;

void solve(){
    int n, m,x,maximum = -1e9 - 1;
    cin >> n >> m;
    pair<int,int> p;
    for(int i = 0; i < n;i++){
        for(int j = 0; j < m;j++){
            cin >> x;
            if(x > maximum){
                maximum = x;
                p.first = i;
                p.second = j;
            }
        }
    }
    int result = max(p.first+1, n - p.first);
    result *= max(p.second+1,m - p.second);
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



