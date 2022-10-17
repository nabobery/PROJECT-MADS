#include <iostream>
using namespace std;

#pragma GCC optimize("Ofast")

int n, m,k,l,result=0;
// to see if an employee is visited or not
bool visited[102] = {false};
// if a[i][j] is true it means employee j ca speak ith language
bool a[102][102] = {false};

void dfs(int x){
    visited[x] = true;
    for(int i = 1; i <= m;i++){
        // if employee x can speak language i
        if(a[i][x]){
            for(int j = 1; j <= n;j++){
                // if employee j is not visited and can speak the same language as employee x, use dfs(j)
                if(!visited[j] && a[i][j]){
                    dfs(j);
                }
            }
        }
    }
}

void solve(){
    cin >> n >> m;
    // to check if there're no edges and n connected components (in this case we need to spend n beridollars)
    bool flag = false;
    for(int i = 1; i <= n;i++){
        cin >> k;
        if(k) flag = true;
        // setting what languages an employee can speak
        for(int j = 0; j < k;j++){
            cin >> l;
            a[l][i] = true;
        }
    }
    if(!flag) cout<<n<<"\n";
    else{
        // calculating number of connected components using dfs
        for(int i = 1; i <= n;i++){
            if(!visited[i]){
                result++;
                dfs(i);
            }
        }
        // number of connected components - 1
        cout<<result-1<<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}




