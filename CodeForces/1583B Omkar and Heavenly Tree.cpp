#include <iostream>
using namespace  std;

void solve(){
    int n, m;
    cin >> n >> m;
    int a,b,c;
    bool visited[n];
    for(int i = 0; i < n;i++) visited[i] = false;
    for(int i = 0; i < m;i++){
        cin >> a >> b >> c;
        visited[b-1] = true;
    }
    int ind;
    for(int i = 0; i < n;i++){
        if(!visited[i]){
            ind = i;
            break;
        }
    }
    for(int i = 0; i < n;i++){
        if(ind != i) cout<<ind+1<<" "<<i+1<<"\n";
        else continue;
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

