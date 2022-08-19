#include <iostream>
using namespace std;

void solve(){
    int n;
    cin >> n;
    char grid[n][n];
    for(int i = 0; i < n;i++){
        for(int j = 0; j < n;j++){
            cin >> grid[i][j];
        }
    }
    bool flag = false;
    for(int i = 0; i < n;i++){
        for(int j = 0; j < n;j++){
            if(i == n-1 || j == n-1) continue;
            else{
                if(grid[i][j] == '1'){
                    if(grid[i+1][j] == '1' || grid[i][j+1] == '1') continue;
                    else{
                        flag = true;
                        break;
                    }
                }
            }
        }
    }
    if(!flag) cout<<"Yes\n";
    else cout<<"No\n";
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
