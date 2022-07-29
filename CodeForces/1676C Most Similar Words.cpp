#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<string> words(n);
    for(int i = 0; i < n;i++) cin >> words[i];
    int result = 1e6, curr = 0;
    for(int i = 0; i < n-1;i++){
        for(int j = i+1; j < n;j++){
            curr = 0;
            for(int k = 0; k < m;k++){
                int a = words[i][k] - '0', b = words[j][k] - '0';
                curr += abs(a-b);
                if(curr > result) break;
            }
            result = min(result,curr);
        }
    }
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



