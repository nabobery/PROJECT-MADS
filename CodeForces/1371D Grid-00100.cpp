#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;
 
#pragma GCC optimize("Ofast")
 
#define ll long long int
 
 
void solve(){
    int n, k;
    cin >> n >> k;
    vector<vector<bool>> grid(n, vector<bool>(n,false));
    for(int i = 0; i < n;i++){
        int x = i, y = 0;
        while(y < n && k > 0){
            grid[x%n][y%n] = true;
            x++;
            y++;
            k--;
        }
        if(k <= 0) break;
    }
    int max_r = 0, min_r = n, max_c = 0, min_c = n;
    for(int i = 0; i < n;i++){
        int temp = 0;
        for(int j = 0; j < n;j++) temp += grid[i][j];
        max_r = max(max_r, temp);
        min_r = min(min_r, temp);
    }
    for(int j = 0; j < n;j++){
        int temp = 0;
        for(int i = 0; i < n;i++) temp += grid[i][j];
        max_c = max(max_c, temp);
        min_c = min(min_c, temp);
    }
    int result = (max_r - min_r) *(max_r - min_r);
    result += (max_c - min_c) * (max_c - min_c);
    cout<<result<<"\n";
    for(int i = 0; i < n;i++){
        for(int j = 0; j < n;j++) cout<<(int)grid[i][j];
        cout<<"\n";
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