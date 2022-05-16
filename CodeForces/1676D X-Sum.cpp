#include <iostream>
#include <algorithm>
using namespace  std;

int mat[200][200];

int simulate(int n, int m, int r, int c){
    int res = 0,i,j;
    for (i = r+1, j = c+1; i < n && j < m; i++, j++) {
        res += mat[i][j];
    }
    for (i = r-1, j = c-1; i >= 0 && j >= 0; i--, j--) {
        res += mat[i][j];
    }
    for (i = r-1, j = c+1; i >= 0 && j < m; i--, j++) {
        res += mat[i][j];
    }
    for (i = r+1, j = c-1; i < n && j >= 0; i++, j--) {
        res += mat[i][j];
    }
    res += mat[r][c];
    return res;
}

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m;j++){
            cin >> mat[i][j];
        }
    }
    int result = 0;
    for(int i = 0; i < n;i++){
        for(int j = 0; j < m;j++){
            result = max(result,simulate(n,m,i,j));
        }
    }
    cout<<result<<"\n";
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}


