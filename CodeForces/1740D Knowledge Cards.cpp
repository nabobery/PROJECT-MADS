#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#pragma GCC optimize("Ofast")

#define ll long long int

void solve(){
    int n, m,k;
    cin >> n >> m >> k;
    bool visited[k];
    bool flag = true;
    int arr[k];
    for(int i = 0; i < k;i++) visited[i] = false;
    int occupied = 2, curr = k-1;
    for(int i = 0; i < k;i++){
        cin >> arr[i];
    }
    for(int i = 0; i < k;i++){
        visited[arr[i]-1] = true;
        while(visited[curr]){
            occupied--;
            curr--;
        }
        occupied++;
        if(occupied > n*m - 2){
            flag = false;
            break;
        }
    }
    cout<<(flag ? "YA\n" : "TIDAK\n");
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

